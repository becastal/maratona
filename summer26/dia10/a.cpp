#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll


//inline int add(int a, int b, int mod){a+=b;if(a>=mod)a-=mod;return a;}
//inline int sub(int a, int b, int mod){a-=b;if(a<0)a+=mod;return a;}
//inline int mul(int a, int b, int mod){return (a*b)%mod;}
//
//const int mod1 = 1000015187;
//const int mod2 = 1000027957;
//// outros primos: 1000041323, 1000015553, 1000028537, 50331653
//// mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count()); // random number
//// const int base = uniform_int_distribution<int>(356, mod1-1)(rng); // alphabet < base < lowest_mod
//const int base = 31;
//struct HS {
//    int n;
//    vector<int> s, t, h1, h2, hi1, hi2, p1, p2;
//    template<typename T>
//    HS(T x) : n(x.size()), s(x.begin(), x.end()), t(x.rbegin(), x.rend()),
//               h1(n), h2(n), hi1(n), hi2(n), p1(n), p2(n) {
//        // evita ter 0 no vetor
//        for (auto& it : s) it += 1;
//        for (auto& it : t) it += 1;
//        p1[0] = p2[0] = 1;
//        h1[0] = h2[0] = s[0];
//        hi1[0] = hi2[0] = t[0];
//        for (int i = 1; i < n; ++i) {
//            p1[i] = mul(base, p1[i-1], mod1);
//            p2[i] = mul(base, p2[i-1], mod2);
//
//            h1[i] = add(mul(base, h1[i-1], mod1), s[i], mod1);
//            h2[i] = add(mul(base, h2[i-1], mod2), s[i], mod2);
//
//            hi1[i] = add(mul(base, hi1[i-1], mod1), t[i], mod1);
//            hi2[i] = add(mul(base, hi2[i-1], mod2), t[i], mod2);
//        }
//    }
//
//    int query(int l, int r, bool inv = false) const {
//        const auto& hs1 = inv ? hi1 : h1;
//        const auto& hs2 = inv ? hi2 : h2;
//        int h1_val = (l == 0) ? hs1[r] : sub(hs1[r], mul(hs1[l-1], p1[r-l+1], mod1), mod1);
//        int h2_val = (l == 0) ? hs2[r] : sub(hs2[r], mul(hs2[l-1], p2[r-l+1], mod2), mod2);
//        return h1_val ^ (h2_val << 29);
//    }
//
//    int query_inv(int a, int b) const {
//        return query(n - b - 1, n - a - 1, true);
//    }
//};

const ll P = 69420;
const ll M = 1e9+9;
signed solve() {
	string S; cin >> S;
	int n = (int)S.size();

    vector<int> base(n), pre(n + 1);
    base[0] = 1;
    for (int i = 1; i < n; i++) {
        base[i] = base[i - 1] * P % M;
    }

    for (int i = 1; i <= n; i++) {
        pre[i] = (pre[i - 1] * P + S[i - 1]) % M;
    }

    auto hash = [&] (int l, int r) -> int {
		//printf("%d, %d\n", l, r);
        int h = (pre[r + 1] - base[r - l + 1] * pre[l] % M + M) % M;
        return h;
    };

	auto da = [&](int m) -> array<int, 2> {
		unordered_map<int, int> C, P;
		C.reserve(1024);
		C.max_load_factor(0.25);
		P.reserve(1024);
		P.max_load_factor(0.25);
		for (int i = 0; i <= n-m; i++) {
			//int h = hash.query(i, i + m - 1);
			int h = hash(i, i + m - 1);
			C[h]++;
			if (!P.count(h)) {
				P[h] = i;
			}
		}
		int resp = LLONG_MAX;
		for (auto [a, b] : C) {
			if (b == 1) {
				resp = min(resp, P[a]);
			}
		}
		if (resp != LLONG_MAX) return {1, resp};
		return {0, -1};
	};

	//vector<int> C(26, 0);
	//for (char c : S) C[c - 'A']++;
	//for (int i = 0; i < n; i++) if (C[S[i] - 'A'] == 1) {
	//	return cout << S[i] << endl, 0;
	//}
	//if (count(all(C), 0) == 25) return cout << S << endl, 0;

	int l = 1, r = n, rest = n, resp = 0;
	while (l <= r) {
		int m = l + (r - l) / 2;

		auto [ok, resp_] = da(m);
		if (ok) {
			r = m - 1;
			rest = m;
			resp = resp_;
		} else {
			l = m + 1;
		}
	}
	cout << S.substr(resp, rest) << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
