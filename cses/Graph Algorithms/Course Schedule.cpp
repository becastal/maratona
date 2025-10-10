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

int solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n);

	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
	}
	
	auto topo_sort = [&]() {
		vector<int> ret(n,-1), vis(n,0);
		
		int pos = n-1, dag = 1;
		function<void(int)> dfs = [&](int v) {
			vis[v] = 1;
			for (auto u : g[v]) {
				if (vis[u] == 1) dag = 0;
				else if (!vis[u]) dfs(u);
			}
			ret[pos--] = v, vis[v] = 2;
		};

		for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);

		if (!dag) ret.clear();	
		return ret;
	};

	auto res = topo_sort();
	if (res.empty()) return cout << "IMPOSSIBLE" << endl, 0;
	for (int i : res) cout << i+1 << ' '; cout << endl;

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
