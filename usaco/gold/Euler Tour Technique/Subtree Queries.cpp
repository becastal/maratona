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
	ll seg[4*MAX], *v;
	int n;
 
	ll build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n_, ll* v_) {
		n = n_, v = v_;
		build();
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return 0;
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	ll update(int i, int x, int p=1, int l=0, int r=n-1) {
		if (i < l or r < i) return seg[p];
		if (l == r) return seg[p] = x;
		int m = (l+r)/2;
		return seg[p] = update(i, x, 2*p, l, m) + update(i, x, 2*p+1, m+1, r);
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
 
	vector<ll> vals_(n, 0);
	for (int u = 0; u < n; u++) {
		vals_[tin[u]] = vals[u];
	}
	seg::build(n, vals_.data());
 
	while (q--) {
		int tp; cin >> tp;
 
		if (tp == 1) {
			int u, x; cin >> u >> x; u--;
			seg::update(tin[u], x);
		} else {
			int u; cin >> u; u--;
			cout << seg::query(tin[u], tout[u]) << endl;
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
