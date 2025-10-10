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

struct DSU {
	vector<int> id, sz;
	DSU(int n) : id(n), sz(n, 1) {
		iota(id.begin(), id.end(), 0);
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	void merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		if (sz[i] < sz[j]) swap(i, j);
		sz[i] += sz[j], id[j] = i;
	}
};

int solve() {
	int n, m; cin >> n >> m;
	vector<tuple<int, int, int>> ed(m);
	for (auto& [w, u, v] : ed) cin >> u >> v >> w, u--, v--;
	
	sort(ed.begin(), ed.end());
	DSU dsu(n);

	vector<vector<pair<int, int>>> g(n);
	for (auto& [w, u, v] : ed) {
		if (dsu.find(u) == dsu.find(v)) continue;

		dsu.merge(u, v);
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}

	vector<int> dist(n, 0);
	function<void(int, int, int)> dfs = [&](int u, int p, int mx) {
		for (auto [v, w] : g[u]) {
			if (v == p) continue;
			dfs(v, u, dist[v] = max(mx, w));
		}
	};
	dfs(0, -1, 0);

	int d; cin >> d;
	vector<int> D(d), E(d);
	for (int& i : D) cin >> i, i = dist[i-1];
	for (int& i : E) cin >> i;

	sort(D.begin(), D.end());
	sort(E.begin(), E.end());

	int res = 0;
	for (int l = 0, r = 0; l < d and r < d; ) {
		if (E[r] >= D[l]) {
			res++, l++, r++;
		} else r++;
	}
	cout << res << endl;
	
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
