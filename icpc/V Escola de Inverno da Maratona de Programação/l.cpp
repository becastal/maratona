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

const int MAX = 2e5+10;
namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
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

namespace hld {
	vector<int> g[MAX];
	int pos[MAX], sz[MAX];
	int peso[MAX], pai[MAX];
	int h[MAX], v[MAX], t;

	void build_hld(int k, int p = -1, int f = 1) {
		v[pos[k] = t++] = peso[k]; sz[k] = 1;
		for (auto& i : g[k]) if (i != p) {
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
	ll query_path(int a, int b) {
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return seg::query(pos[b], pos[a]);
		return seg::query(pos[h[a]], pos[a]) + query_path(pai[h[a]], b);
	}
	void update_path(int a, int b, int x) {
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return (void)seg::update(pos[b], pos[a], x);
		seg::update(pos[h[a]], pos[a], x); update_path(pai[h[a]], b, x);
	}
}

int solve() {
	int n, m; cin >> n >> m;

	vector<pair<int, int>> ar(m);
	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		ar[i].f = u, ar[i].s = v;
	}

	int t = 0;
	stack<int> s;
	vector<int> vis(n, 0), id(n), comp(n);
	function<void()> tarjan = [&] {
		vector<int> st, low(n);
		int tcnt = 0;

		for (int start = 0; start < n; ++start) {
			if (!vis[start]) {
				struct Frame { int u, i, parent; };
				vector<Frame> call;
				call.reserve(n);
				call.push_back({start, 0, -1});
				while (!call.empty()) {
					auto &f = call.back();
					int u = f.u;

					if (f.i == 0) {
						id[u]  = low[u] = tcnt++;
						vis[u] = 2;
						st.push_back(u);
					}

					if (f.i < (int)g[u].size()) {
						int v = g[u][f.i++];
						if (!vis[v]) {
							call.push_back({v, 0, (int)call.size() - 1});
						}
						else if (vis[v] == 2) {
							low[u] = min(low[u], id[v]);
						}
					}
					else {
						if (f.parent != -1) {
							int p = call[f.parent].u;
							low[p] = min(low[p], low[u]);
						}
						if (low[u] == id[u]) {
							int v;
							do {
								v = st.back(); st.pop_back();
								vis[v]   = 1;
								comp[v]  = u;
							} while (v != u);
						}
						call.pop_back();
					}
				}
			}
		}
	};
	tarjan();

	for (auto& [a, b] : ar) {
		a = comp[a], b = comp[b];
	}
	sort(ar.begin(), ar.end());
	ar.erase(unique(ar.begin(), ar.end()), ar.end());

	vector<vector<int>> g_(n);
	for (auto [a, b] : ar) {
		g_[a].push_back(b);
		hld::g[a].push_back(b);
		hld::g[b].push_back(a);
	}

	vector<int> ult(n, -1), vis_(n, 0);
	for (int i = 0; i < n; i++) {
		if (vis_[i]) continue;

		vector<int> cam;
		int u;
		for (u = i; !vis_[u] and !g_[u].empty(); u = g_[u][0]) {
			cam.push_back(u);
			vis_[u] = 1;
		}

		int x;
		if (vis_[u]) x = ult[u];
		else {
			vis_[u] = 1;
			x = ult[u] = u;
		}

		for (int& j : cam) ult[j] = x;
	}

	int q; cin >> q;
	vector<vector<pair<int, int>>> qs(n);
	for (int i = 0, a, b; i < q; i++) {
		cin >> a >> b; a--, b--;
		a = comp[a], b = comp[b];
		qs[b].emplace_back(a, i);
	}

	vector<int> res(q);
	for (int i = 0; i < n; i++) hld::peso[i] = 0;
	hld::build();
	for (int i = 0; i < n; i++) {
		hld::update_path(i, i, +1);
		for (auto [u, idx] : qs[i]) {
			res[idx] = hld::query_path(u, ult[u]);
		}
		hld::update_path(i, i, -1);
	}

	for (int i : res) cout << (i ? "Sim" : "Nao") << endl;

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
