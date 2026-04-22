#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

template<int MOD> struct str_hash {
	static int P;
	vector<ll> h, p;
	str_hash(string s) : h(s.size()), p(s.size()) {
		p[0] = 1, h[0] = s[0];
		for (int i = 1; i < s.size(); i++)
			p[i] = p[i - 1]*P%MOD, h[i] = (h[i - 1]*P + s[i])%MOD;
	}
	ll operator()(int l, int r) { // retorna hash s[l...r]
		ll hash = h[r] - (l ? h[l - 1]*p[r - l + 1]%MOD : 0);
		return hash < 0 ? hash + MOD : hash;
	}
};
template<int MOD> int str_hash<MOD>::P = uniform(256, MOD - 1);

struct Bit {
	int n;
	vector<ll> bit;
	Bit(int _n=0) : n(_n), bit(n + 1) {}
	Bit(vector<int>& v) : n(v.size()), bit(n + 1) {
		for (int i = 1; i <= n; i++) {
			bit[i] += v[i - 1];
			int j = i + (i & -i);
			if (j <= n) bit[j] += bit[i];
		}
	}
	void update(int i, ll x) { // soma x na posicao i
		for (i++; i <= n; i += i & -i) bit[i] += x;
	}
	ll pref(int i) { // soma [0, i]
		ll ret = 0;
		for (i++; i; i -= i & -i) ret += bit[i];
		return ret;
	}
	ll query(int l, int r) {  // soma [l, r]
		return pref(r) - pref(l - 1);
	}
	int upper_bound(ll x) {
		int p = 0;
		for (int i = __lg(n); i+1; i--)
			if (p + (1<<i) <= n and bit[p + (1<<i)] <= x)
				x -= bit[p += (1 << i)];
		return p;
	}
};

int solve() {
	string S; cin >> S;
	int n = (int)S.size();
	string S_(S);
	reverse(all(S_));
	str_hash<(int)1e9+9> H(S), H_(S_);

	auto pal = [&](int l, int r) {
		int r_ = n - 1 - l, l_ = n - 1 - r;
		return H(l, r) == H_(l_, r_);
	};

	vector<vector<int>> Add(n);
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) if (pal(i, j)) {
			Add[i].push_back(j);
		}
	}

	int q; cin >> q;
	vector<vector<array<int, 2>>> Queries(n);
	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r; l--, r--;
		Queries[l].push_back({r, i});
	}

	vector<int> Res(q);
	Bit bit(n);
	for (int l = n-1; l >= 0; l--) {
		for (int r : Add[l]) {
			bit.update(r, +1);			
		}
		for (auto [r, id] : Queries[l]) {
			Res[id] = bit.pref(r);	
		}
	}

	for (int i : Res) {
		cout << i << endl;
	}

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

