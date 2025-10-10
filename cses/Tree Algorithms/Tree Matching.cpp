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
	int n; cin >> n;
	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<vector<int>> dp(n, vector<int>(2, 0));
	function<int(int, int)> dfs = [&](int u, int p) {
		for (int v : g[u]) if (v != p) {
			dp[u][1] += dfs(v, u);
		}

		int mel = 0;
		for (int v : g[u]) if (v != p) {
			mel = max(mel, 1 + dp[v][1] - dp[v][0]);
		}
		
		return dp[u][0] = dp[u][1] + mel;
	};
	dfs(0, -1);
	cout << max(dp[0][0], dp[0][1]) << endl;

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
