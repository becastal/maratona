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

	int k; cin >> k;
	vector<vector<int>> vis(n, vector<int>(k, 0));

	function<void(int, int)> dfs = [&](int u, int ki) {
		vis[u][ki] = 1;

		int ki_ = (ki + 1) % k;
		for (int v : g[u]) {
			if (vis[v][ki_]) continue;
			dfs(v, ki_);
		}
	};
	dfs(0, 0);

	cout << (vis[n-1][0] ? "Sim" : "Nao") << endl;

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
