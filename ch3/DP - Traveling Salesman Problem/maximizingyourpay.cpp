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

void solve(int n) {
	int m; cin >> m;

	vector<vector<int>> d(n, vector<int>(n, 0));
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		d[u][v] = d[v][u] = 1;
	}

	vector<vector<int>> dp((1 << n), vector<int>(n, INF));
	dp[1][0] = 0;

	int res = 1;
	for (int i = 0; i < (1 << n); i++) {
		for (int u = 0; u < n; u++) {
			if (!(i & (1 << u))) continue;

			if (d[u][0] and dp[i][u] != INF) res = max(res, __builtin_popcount(i));

			for (int v = 0; v < n; v++) {
				if (i & (1 << v) or !d[u][v]) continue;

				int ni = i | (1 << v);	
				dp[ni][v] = min(dp[ni][v], dp[i][u] + d[u][v]);
			}
		}
	}

	cout << res << endl;	
}

int main()
{
    _;

	int n;
	while (cin >> n and n) {
		solve(n);
	}
	
    
    return(0);
}
