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
	vector<vector<int>> G(n);
	for (int i = 0, u, v; i < m; i++) { 
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	vector<int> C(n, -1), Cont(2);
	function<int(int, int)> dfs = [&](int u, int c) {
		Cont[C[u] = c]++;
		for (int v : G[u]) {
			if (C[v] == -1) {
				if (!dfs(v, c ^ 1)) return 0;
			} else if (C[v] == C[u]) return 0;
		}
		return 1;
	};

	vector<int> Vis(n);
	function<void(int)> dfs2 = [&](int u) {
		Vis[u] = 1;
		for (int v : G[u]) if (!Vis[v]) {
			dfs2(v);
		}
	};

	int res = 0;
	for (int u = 0; u < n; u++) if (!Vis[u]) {
		Cont[0] = Cont[1] = 0;
		if (dfs(u, 0)) {
			res += max(Cont[0], Cont[1]);
		}
		dfs2(u);
	}
	cout << res << endl;

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

