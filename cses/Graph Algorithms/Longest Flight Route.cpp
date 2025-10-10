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

	vector<vector<int>> g(n), g_(n);
	vector<int> peso(n, 0), vis(n, 0), dp(n, -INF); dp[0] = 1;
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g_[v].push_back(u);
		peso[v]++;
	}

	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;

		for (int v : g[u]) {
			dp[v] = max(dp[v], dp[u] + 1);
			if (--peso[v] == 0) dfs(v);
		}
	};

	for (int i = 0; i < n; i++) {
		if (!vis[i] and !peso[i]) {
			dfs(i);
		}
	}
	if (dp.back() < 0) return cout << "IMPOSSIBLE" << endl, 0;


	int u = n-1;
	vector<int> res = {u};
	for (int d = dp[u]; d > 1; ) {
		for (int v : g_[u]) {
			if (dp[v] == dp[u] - 1) {
				u = v;	
				d--;
				break;
			}
		}
		res.push_back(u);
	}
	reverse(res.begin(), res.end());
	cout << dp[res.back()] << endl;
	for (int i : res) cout << i + 1 << ' '; cout << endl;
	

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
