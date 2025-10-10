#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;
	
	string s; cin >> s;
	vector<int> in(n, 0), vis(n, 0);
	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		in[v]++;
	}

	int dag = 1;
	function<void(int)> dfs1 = [&](int u) {
		vis[u] = 1;

		for (int v : g[u]) {
			if (vis[v] == 1) {
				dag = 0;
				return;
			}
			if (!vis[v]) dfs1(v);
		}
		vis[u] = 2;
	};

	for (int i = 0; i < n; i++) {
		if (!vis[i]) dfs1(i);
	}
	if (!dag) return cout << -1 << endl, 0;

	int res = 1;
	vector<vector<int>> dp(n, vector<int>(26, 0));

	for (int i = 0; i < n; i++) {
		dp[i][s[i]-'a'] = 1;
	}
	function<void(int)> dfs2 = [&](int u) {
		vis[u] = 1;

		for (int v : g[u]) {
			for (int i = 0; i < 26; i++) {
				dp[v][i] = max(dp[v][i], dp[u][i] + (i == (s[v] - 'a')));
				res = max(res, dp[v][i]);
			}
			if (!--in[v]) dfs2(v);
		}
	};

	fill(all(vis), 0);
	for (int i = 0; i < n; i++) if (!vis[i] and !in[i]) {
		dfs2(i);	
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
