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

void solve() {
	int n, m; cin >> n >> m;

	vector<int> id(26);
	vector<char> V(n);
	for (int i = 0; i < n; i++) {
		cin >> V[i];
		id[V[i]-'A'] = i;
	}

	vector<vector<int>> d(n, vector<int>(n, 0));
	for (int i = 0; i < m; i++) {
		char u, v; cin >> u >> v; u -= 'A', v -= 'A';
		d[id[u]][id[v]] = d[id[v]][id[u]] = 1;
	}

	vector<vector<int>> dp((1 << n), vector<int>(n, INF));
	vector<vector<pair<int, int>>> pai((1 << n), vector<pair<int, int>>(n, {-1, -1}));
	dp[1][0] = 0;

	for (int i = 0; i < (1 << n); i++) {
		for (int u = 0; u < n; u++) {
			if (!(i & (1 << u))) continue;

			for (int v = 0; v < n; v++) {
				if (i & (1 << v)) continue;
				
				int ni = i | (1 << v);
				if (d[u][v] and d[u][v] + dp[i][u] < dp[ni][v]) {
					dp[ni][v] = d[u][v] + dp[i][u];
					pai[ni][v] = pair<int, int>(i, u);
				}
			}
		}
	}

	if (dp[(1 << n)-1][n-1] == INF) {
		cout << "impossible" << endl;
		return;
	}

	
	vector<char> res = {V[0]};
	vector<vector<int>> memo((1 << n), vector<int>(n, -1));
	function<bool(int i, int u)> dfs = [&](int i, int u) {
		if (i == (1 << n)-1 and u == n-1) return 1;
		if (memo[i][u] != -1) return memo[i][u];

		set<char> prox;
		for (int v = 0; v < n; v++) {
			if (!(i & (1 << v)) and d[u][v] and dp[i | (1 << v)][v] == dp[i][u] + d[u][v]) {
				prox.emplace(V[v]);
			}
		}

		for (char v : prox) {
			int vi = id[v-'A'];
			
			res.push_back(v);
			if (dfs(i | (1 << vi), vi)) return memo[i][u] = 1;
			res.pop_back();
		}

		memo[i][u] = 0;
		return 0;
	};
	dfs(1, 0);
	
	for (char i : res) cout << i; cout << endl;
}

int main()
{
    _;

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case " << t << ": ";
		solve();
	}
    
    return(0);
}
