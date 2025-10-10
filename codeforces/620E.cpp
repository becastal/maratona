#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const int MAX = 4e5+10;
namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	ll* v;
	int n;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = -1;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) | build(2*p+1, m+1, r);
	}
	void build(int n2, ll* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		if (lazy[p] == -1) return;
		seg[p] = lazy[p];
		if (l != r) lazy[2*p] = lazy[p], lazy[2*p+1] = lazy[p];
		lazy[p] = -1;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) | query(a, b, 2*p+1, m+1, r);
	}
	ll update(int a, int b, ll x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] = x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) | update(a, b, x, 2*p+1, m+1, r);
	}
}

int solve() {
	int n, q; cin >> n >> q;
	vector<ll> A(n);
	for (ll& i : A) cin >> i;

	vector<vector<int>> G(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int t = 0;
	vector<int> L(n), R(n);
	function<void(int, int)> dfs = [&](int u, int p) {
		L[u] = t++;
		for (int v : G[u]) if (v != p) {
			dfs(v, u);
		}
		R[u] = t-1;
	};
	dfs(0, -1);

	vector<ll> B(n);
	for (int i = 0; i < n; i++) {
		B[L[i]] = (1LL << A[i]);
	}
	seg::build(n, B.data());

	while (q--) {
		int tp; cin >> tp;
		if (tp == 1) {
			int u, x; cin >> u >> x; u--;
			seg::update(L[u], R[u], (1LL << x));
		} else {
			int u; cin >> u; u--;
			cout << __builtin_popcountll(seg::query(L[u], R[u])) << endl;
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

