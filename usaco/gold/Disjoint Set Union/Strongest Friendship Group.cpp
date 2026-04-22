#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

struct Dsu {
	int n;
	vector<int> id, sz;

	Dsu(int n_) : n(n_), id(n), sz(n, 1) {
		iota(all(id), 0);
	}

	int find(int u) {
		return u == id[u] ? u : id[u] = find(id[u]);
	}

	int merge(int u, int v) {
		if ((u = find(u)) == (v = find(v))) return 0;
		if (sz[u] < sz[v]) swap(u, v);
		sz[u] += sz[v];
		id[v] = id[u];
		return 1;
	}
};

int solve() {
	int n, m; cin >> n >> m;

	vector<vector<int>> G(n);
	vector<int> Deg(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
		Deg[u]++, Deg[v]++;
	}

	set<array<int, 2>> St;
	for (int u = 0; u < n; u++) { 
		St.insert({Deg[u], u});
	}

	vector<array<int, 2>> O;
	while (St.size()) {
		auto [degu, u] = *St.begin(); St.erase(*St.begin());
		for (int v : G[u]) if (St.count({Deg[v], v})) {
			St.erase({Deg[v], v});
			St.insert({--Deg[v], v});
		}
		O.push_back({Deg[u], u});
	}
	reverse(all(O));

	vector<int> Vivo(n, 0);
	Dsu dsu(n);
	int mn = LLONG_MAX, res = LLONG_MIN;
	for (auto [degu, u] : O) {
		mn = degu;
		Vivo[u] = 1;

		for (int v : G[u]) if (Vivo[v]) {
			dsu.merge(u, v);	
			res = max(res, mn * dsu.sz[dsu.find(u)]);
		}
	}
	cout << res << endl;

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

