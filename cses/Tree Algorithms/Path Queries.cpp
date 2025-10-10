#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

const int MAX = 4e5+20;
namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = 0;
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void prop(int p, int l, int r) {
		seg[p] += lazy[p]*(r-l+1);
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) + update(a, b, x, 2*p+1, m+1, r);
	}
};

int solve() {
	int n, q; cin >> n >> q;

	vector<ll> vals(n);
	for (ll& i : vals) cin >> i;

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int t = 0;
	vector<int> tin(n), tout(n);
	function<void(int, int)> dfs = [&](int u, int p) {
		tin[u] = t++;
		for (int v : g[u]) if (v != p) {
			dfs(v, u);
		}
		tout[u] = t-1;
	};
	dfs(0, -1);

	seg::n = n;
	seg::build();
	for (int u = 0; u < n; u++) {
		seg::update(tin[u], tout[u], vals[u]);
	}

	while (q--) {
		int tp; cin >> tp;

		if (tp == 1) {
			int u, x; cin >> u >> x; u--;
			ll diff = x - vals[u];
			vals[u] = x;
			seg::update(tin[u], tout[u], diff);
		} else {
			int u; cin >> u; u--;
			cout << seg::query(tin[u], tin[u]) << endl;
		}
	}

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
