#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

struct Bit {
	int n;
	vector<ll> F;
	Bit(int n_) : n(n_), F(n_ + 1, 0) {};
	void update(int i, ll x) {
		for (++i; i <= n; i+=i&-i) F[i] += x;
	}
	ll pref(int i) {
		ll res = 0;
		for (++i; i; i-=i&-i) res += F[i];
		return res;
	}
	ll query(int l, int r) {
		return pref(r) - pref(l-1);
	}
};

int solve() {
	int n, q; cin >> n >> q;

	vector<vector<int>> G(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int t = 0;
	vector<int> D(n, 0), L(n), R(n);
	function<void(int, int)> dfs = [&](int u, int p) {
		L[u] = t++;
		for (int v : G[u]) if (v != p) {
			D[v] = D[u] + 1;
			dfs(v, u);
		}
		R[u] = t-1;
	};
	dfs(0, -1);

	Bit bit(n);
	while (q--) {
		int a, b, x; cin >> a >> b >> x; a--, b--;

		if (x) {
			bit.update(L[a], +x);
			bit.update(L[b], -x);
		} else {
			int c = (D[a] >= D[b] ? a : b);
			cout << abs(bit.query(L[c], R[c])) << endl;
		}
	}

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
