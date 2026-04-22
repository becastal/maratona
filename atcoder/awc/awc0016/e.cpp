#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m; cin >> n >> m;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}
	int s, t; cin >> s >> t; s--, t--;

	vector<vector<int>> D(n, vector<int>(n, LLONG_MAX));
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		D[u][v] = D[v][u] = w;
	}

	for (int b = 0; b < n; b++) {
		for (int a = 0; a < n; a++) {
			for (int c = 0; c < n; c++) if (max(D[a][b], D[b][c]) != LLONG_MAX) {
				D[a][c] = min(D[a][c], D[a][b] + D[b][c]);
			}
		}
	}

	vector<vector<int>> dp((1 << n), vector<int>(n, LLONG_MIN));
	dp[(1 << s)][s] = A[s];

	for (int mask = 0; mask < (1 << n); mask++) {
		for (int u = 0; u < n; u++) if (mask >> u & 1) {
			for (int v = 0; v < n; v++) if (mask >> v & 1 ^ 1) {
				int mask_ = mask | (1 << v);
				if (dp[mask][u] != LLONG_MIN and D[u][v] != LLONG_MIN) {
					dp[mask_][v] = max(dp[mask_][v], dp[mask][u] + A[v] - D[u][v]);
				}
			}
		}
	}

	int res = LLONG_MIN;
	for (int mask = 0; mask < (1 << n); mask++) {
		res = max(res, dp[mask][t]);
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

