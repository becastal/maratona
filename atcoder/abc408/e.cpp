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
	vector<vector<pair<int, int>>> g(n);

	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}

	int res = INT_MAX, agr = 0;
	for (int i = 30; i >= 0; i--) {

		vector<int> vis(n, 0);
		function<void(int)> dfs = [&](int u) {
			vis[u] = 1;
			
			for (auto [v, w] : g[u]) {
				if (vis[v] or (w & (1 << i))) continue;
				if ((agr & w) == 0) dfs(v);
			}
		};
		dfs(0);

		if (vis[n-1]) res ^= (1 << i), agr |= (1 << i);
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
