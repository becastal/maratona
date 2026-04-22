#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n; cin >> n;

	vector<array<int, 2>> P(n);
	for (auto& [a, b] : P) {
		cin >> a >> b;
	}

	vector<vector<int>> D(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			auto [xi, yi] = P[i];
			auto [xj, yj] = P[j];
			D[i][j] = D[j][i] = (xi - xj) * (xi - xj) + (yi - yj) * (yi - yj);
		}
	}

	vector<vector<int>> dp(1 << n, vector<int>(n, LLONG_MAX));
	dp[1 << 0][0] = 0;

	for (int mask = 0; mask < (1 << n); mask++) {
		for (int u = 0; u < n; u++) if (mask >> u & 1) {
			for (int v = 0; v < n; v++) if (mask >> v & 1 ^ 1) {
				int mask_ = mask | (1 << v);
				if (dp[mask][u] != LLONG_MAX) {
					dp[mask_][v] = min(dp[mask_][v], dp[mask][u] + D[u][v]);
				}
			}
		}
	}

	int res = LLONG_MAX;
	for (int u = 1; u < n; u++) {
		res = min(res, dp[(1 << n) - 1][u] + D[u][0]);
	}
	cout << res << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

