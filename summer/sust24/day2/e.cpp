#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

// SegTree
//
// Recursiva com Lazy Propagation
// Query: soma do range [a, b]
// Update: soma x em cada elemento do range [a, b]
// Pode usar a seguinte funcao para indexar os nohs:
// f(l, r) = (l+r)|(l!=r), usando 2N de memoria
//
// Complexidades:
// build - O(n)
// query - O(log(n))
// update - O(log(n))

const int MAX = 250'010;
namespace seg {
	int seg[4*MAX], lazy[4*MAX];
	int n, *v;

	int build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) ^ build(2*p+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		if (!lazy[p]) return;
		seg[p] = lazy[p];
		lazy[p] = 0;
	}
	int query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) ^ query(a, b, 2*p+1, m+1, r);
	}
	int update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] = x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) ^ update(a, b, x, 2*p+1, m+1, r);
	}
};

// HLD - vertice
//
// SegTree de soma
// query / update de soma dos vertices
//
// Complexidades:
// build - O(n)
// query_path - O(log^2 (n))
// update_path - O(log^2 (n))
// query_subtree - O(log(n))
// update_subtree - O(log(n))

// namespace seg { ... }

namespace hld {
	vector<int> g[MAX];
	int pos[MAX], sz[MAX];
	int peso[MAX], pai[MAX];
	int h[MAX], v[MAX], d[MAX], t;

	void build_hld(int k, int p = -1, int f = 1) {
		v[pos[k] = t++] = peso[k]; sz[k] = 1;
		for (auto& i : g[k]) if (i != p) {
			d[i] = d[k] + 1;
			pai[i] = k;
			h[i] = (i == g[k][0] ? h[k] : i);
			build_hld(i, k, f); sz[k] += sz[i];

			if (sz[i] > sz[g[k][0]] or g[k][0] == p) swap(i, g[k][0]);
		}
		if (p*f == -1) build_hld(h[k] = k, -1, t = 0);
	}
	void build(int root = 0) {
		t = 0;
		build_hld(root);
		seg::build(t, v);
	}
	int query_path(int a, int b) {
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return seg::query(pos[b], pos[a]);
		return seg::query(pos[h[a]], pos[a]) ^ query_path(pai[h[a]], b);
	}
	void update_path(int a, int b, int x) {
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return (void)seg::update(pos[b], pos[a], x);
		seg::update(pos[h[a]], pos[a], x); update_path(pai[h[a]], b, x);
	}
	int lca(int a, int b) {
		if (pos[a] < pos[b]) swap(a, b);
		return h[a] == h[b] ? b : lca(pai[h[a]], b);
	}
	int dist(int a, int b) {
		return d[a] + d[b] - 2 * d[lca(a, b)];
	}
}

mt19937_64 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int solve() {
	int n, q; cin >> n >> q;	

	vector<int> H(n), X(n);
	for (int i = 0; i < n; i++) {
		H[i] = uniform(1, 1000000000000000000LL);
		//H[i] = (1 << i);
		if (i) X[i] = X[i-1];
		X[i] ^= H[i];
	}
	for (int i = 0, p; i < n; i++) {
		cin >> p; p--;
		hld::peso[i] = H[p];
	}

	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v; u--, v--;
		hld::g[u].push_back(v);
		hld::g[v].push_back(u);
	}
	hld::build();

	while (q--) {
		int tp; cin >> tp;

		if (tp == 1) {
			int a, b; cin >> a >> b; a--, b--;
			int l = hld::dist(a, b);	

//			cout << l << endl;
//			cout << X[l] << ", " <<hld::query_path(a, b) << endl;
			cout << (X[l] == hld::query_path(a, b) ? "Yes" : "No") << endl;
		} else if (tp == 2) {
			int a, z; cin >> a >> z; a--, z--;	
			hld::update_path(a, a, H[z]);
		}
	}

	for (int i = 0; i < n; i++) {
		hld::g[i].clear();
	}

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

