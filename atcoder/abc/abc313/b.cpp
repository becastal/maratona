#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;

	vector<vector<int>> G(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
	}

	vector<int> vis(n, 0);
	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;
		for (int v : G[u]) if (!vis[v]) {
			dfs(v);
		}
	};

	int res = -1;
	for (int u = 0; u < n; u++) {
		fill(all(vis), 0);
		dfs(u);	
		if (count(all(vis), 1) == n) {
			if (res != -1) return cout << -1 << endl, 0;
			res = u + 1;
		}
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

