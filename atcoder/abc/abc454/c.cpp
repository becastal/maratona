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

	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b; a--, b--;
		G[a].push_back(b);
	}

	vector<int> Vis(n);
	int res = 0;
	function<void(int)> dfs = [&](int u) {
		Vis[u] = 1;
		res++;

		for (int v : G[u]) if (!Vis[v]) {
			dfs(v);
		}
	};
	dfs(0);
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

