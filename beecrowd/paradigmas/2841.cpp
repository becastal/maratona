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

int main()
{
    _;

	int n; cin >> n;
	vector<int> val(n);
	for (int& i : val) cin >> i;

	vector<int> pai(n, -1), filhos(n, 0);
	vector<vector<int>> g(n);
	for (int i = 1; i < n; i++) {
		cin >> pai[i]; pai[i]--;
		filhos[pai[i]]++;
		g[i].push_back(pai[i]);
		g[pai[i]].push_back(i);
	}

	stack<int> S;
	auto bfs = [&]() {
		queue<int> q; q.push(0);
		vector<int> d(n, -1); d[0] = 0;

		while (!q.empty()) {
			int u = q.front(); q.pop();
			S.push(u);

			for (int v : g[u]) {
				if (d[v] != -1) continue;

				q.push(v);
				d[v] = d[u] + 1;
			}
		}
	};
	bfs();

	// dp[u][b]: res em mim me escolhendo ou nao
	vector<vector<int>> dp(n, vector<int>(2, 0));
	while (!S.empty()) {
		int u = S.top(); S.pop();
		
		if (filhos[u] == 0) {
			dp[u][0] = 0;
			dp[u][1] = val[u];
			continue;
		}

		dp[u][1] = val[u];
		for (int v : g[u]) {
			if (v == pai[u]) continue;
			
			dp[u][0] += max(dp[v][0], dp[v][1]);
			dp[u][1] += dp[v][0];
		}

	}

	cout << max(dp[0][1], dp[0][0]) << endl;
    
    return(0);
}
