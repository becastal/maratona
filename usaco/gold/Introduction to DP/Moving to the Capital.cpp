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

	vector<int> d(n, -1);
	auto bfs = [&]() {
		queue<int> q; q.emplace(0);
		d[0] = 0;

		while (q.size()) {
			int u = q.front(); q.pop();	

			for (int v : g[u]) {
				if (d[v] != -1) continue;
				q.emplace(v);
				d[v] = d[u] + 1;
			}
		}
	};
	bfs();

	vector<int> U(n);
	iota(U.begin(), U.end(), 0);

	sort(U.begin(), U.end(), [&](int a, int b) {
		return d[a] > d[b];
	});

	vector<vector<int>> dp(n, vector<int>(2, INF));
	for (int i = 0; i < n; i++) {
		dp[i][0] = dp[i][1] = d[i];
	}

	for (int u : U) {
		for (int v : g[u]) {
			if (d[v] > d[u]) {
				dp[u][0] = min(dp[u][0], dp[v][0]);
				dp[u][1] = min(dp[u][1], dp[v][1]);
			} else {
				dp[u][1] = min(dp[u][1], d[v]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << min(dp[i][1], dp[i][0]) << " \n"[i==n-1];
	}

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
