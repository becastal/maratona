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

	for (int i = 0, u, v, su, sv; i < m; i++) {
		cin >> u >> v >> su >> sv; u--, v--;
		if (su > sv) g[u].push_back(v);
		else g[v].push_back(u);
	}

	int ciclo = 0, res = 0;
	vector<int> vis(n);
	function<void(int, int)> dfs = [&](int u, int u_) {
		vis[u] = 1;
		for (int v : g[u]) {
			ciclo |= v == u_;
			if (vis[v]) continue;
			dfs(v, u_);
		}
	};

	for (int i = 0; i < n; i++) {
		fill(vis.begin(), vis.end(), 0);
		ciclo = 0;
		dfs(i, i);
		res += ciclo;
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
