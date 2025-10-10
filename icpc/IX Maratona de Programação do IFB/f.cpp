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
		g[v].push_back(u);
	}

	vector<int> vis(n, 0);
	int arv = 1;

	function<void(int, int)> dfs = [&](int u, int p) {
		vis[u] = 1;

		for (int v : g[u]) {
			if (vis[v]) {
				arv &= (v == p);
				continue;
			}
			dfs(v, u);
		}
	};

	int res = 0;
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;

		arv = 1;
		dfs(i, -1);
		res += arv;
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
