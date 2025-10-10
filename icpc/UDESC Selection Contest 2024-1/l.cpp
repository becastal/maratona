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
	
	vector<vector<int>> g(n), cor(2);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> vis(n, -1);
	function<int(int, int)> dfs = [&](int u, int c) {
		cor[c].push_back(u);
		vis[u] = c;

		for (int v : g[u]) {
			if (vis[v] == -1) {
				if (!dfs(v, c ^ 1)) return 0;
			} else if (vis[v] == vis[u]) {
				return 0;
			}
		}
		return 1;
	};


	for (int i = 0; i < n; i++) {
		if (vis[i] == -1) if (!dfs(i, 0)) return cout << "IMPOSSIVEL" << endl, 0;
	}

	cout << "POSSIVEL" << endl << cor[0].size() << ' ' << cor[1].size() << endl;
	for (int i : cor[0]) cout << i + 1 << ' '; cout << endl;
	for (int i : cor[1]) cout << i + 1 << ' '; cout << endl;

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
