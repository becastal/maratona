#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

template<int MOD>
struct str_hash {
    static int p;
    int n;
    vector<ll> H, H_, P;

    str_hash(const string &s) : n((int)s.size()), H(n), H_(n), P(n+1, 1) {
        for (int i = 1; i <= n; i++) {
            P[i] = (P[i - 1] * p) % MOD;
        }

        H[0] = s[0];
        for (int i = 1; i < n; i++) {
            H[i] = (H[i - 1] * p + s[i]) % MOD;
        }

        string rs = s;
        reverse(all(rs));

        H_[0] = rs[0];
        for (int i = 1; i < n; i++) {
            H_[i] = (H_[i - 1] * p + rs[i]) % MOD;
        }
    }

	int operator()(int l, int r, int rev = 0) {
		if (rev) {
			int r_ = n - 1 - l;
			int l_ = n - 1 - r;
			r = r_, l = l_;
		}
		const auto& A = (rev ? H_ : H);

		ll ans = A[r] - (l ? (A[l - 1] * P[r - l + 1]) % MOD : 0);
		ans %= MOD;
		if (ans < 0) {
			ans += MOD;
		}
		return ans;
	}

	int pal(int l, int r) {
		return (*this)(l, r) == (*this)(l, r, 1);
	}
};

template<int MOD>
int str_hash<MOD>::p = uniform(256, MOD - 1);
const int _1e9 = 1e9+9;


int solve() {
	string S; cin >> S;
	int n = (int)S.size();
	str_hash<_1e9> H(S);

	vector<int> dp(n + 1, 0);
	for (int tam = 1; tam <= n; tam++) {
		if (H.pal(0, tam - 1)) {
			dp[tam] = dp[tam / 2] + 1;
		} else {
			dp[tam] = 0;
		}
	}

	cout << accumulate(all(dp), 0LL) << endl;

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

