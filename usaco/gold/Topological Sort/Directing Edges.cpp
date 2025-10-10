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

int solve() {
	int n, m; cin >> n >> m;

	vector<vector<pair<int, int>>> g(n);
	vector<tuple<int, int, int>> ed;
	for (int i = 0, w, u, v; i < m; i++) {
		cin >> w >> u >> v; u--, v--;
		g[u].emplace_back(v, w);
		ed.emplace_back(w, u, v);
	}

	auto topo_sort = [&]() {
		vector<int> ret(n,-1), vis(n,0);
		
		int pos = n-1, dag = 1;
		function<void(int)> dfs = [&](int v) {
			vis[v] = 1;
			for (auto [u, w] : g[v]) if (w) {
				if (vis[u] == 1) dag = 0;
				else if (!vis[u]) dfs(u);
			}
			ret[pos--] = v, vis[v] = 2;
		};

		for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);

		if (!dag) ret.clear();	
		return ret;
	};

	auto topo = topo_sort();

	if (topo.empty()) return cout << "NO" << endl, 0;
	vector<int> pos(n, -1);
	for (int i = 0; i < n; i++) {
		pos[topo[i]] = i;
	}

	vector<vector<int>> g2(n);
	for (auto& [w, u, v] : ed) {
		if (!w and pos[u] > pos[v]) swap(u, v);
		//cout << u+1 << ' ' << v+1 << endl;
		g2[u].push_back(v);
	}

	int dag = 1;
	vector<int> vis(n, 0);
	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;
		for (int v : g2[u]) {
			if (vis[v] == 1) dag = 0;
			else if (!vis[v]) dfs(v);
		}
		vis[u] = 2;
	};
	for (int i = 0; i < n and dag; i++) if (!vis[i]) {
		dfs(i);
	}
	if (!dag) return cout << "NO" << endl, 0;

	cout << "YES" << endl;
	for (auto [w, u, v] : ed) cout << u+1 << ' ' << v+1 << endl;

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
