#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m; cin >> n >> m;

	vector<int> Vis(n);
	vector<vector<int>> G(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int vertices = 0, arestas2 = 0;
	function<void(int)> dfs = [&](int u) {
		Vis[u] = 1;
		vertices++;
		arestas2 += G[u].size();

		for (int v : G[u]) {
			if (!Vis[v]) {
				dfs(v);
			}
		}
	};

	int res = 0;
	for (int i = 0; i < n; i++) if (!Vis[i]) {
		vertices = arestas2 = 0;
		dfs(i);

		int arestas = arestas2 / 2;
		res += vertices * (vertices - 1) / 2 - arestas;
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

