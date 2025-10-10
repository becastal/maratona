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

int main()
{
    _;

	int n, m; cin >> n >> m;
	vector<vector<int>> g(n);
	vector<int> deg(n, 0);

	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		deg[u]++, deg[v]++;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> vis(n, 0);
	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;	
		for (int v : g[u]) {
			if (!vis[v]) dfs(v);
		}
	};
	dfs(0);

	cout << (count(deg.begin(), deg.end(), 2) == n and
			 count(vis.begin(), vis.end(), 1) == n
			? "Yes" : "No") << endl;
    
    return(0);
}
