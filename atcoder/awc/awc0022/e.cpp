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

	vector<vector<int>> D(n, vector<int>(n, LLONG_MAX));
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		D[u][v] = D[v][u] = w;
	}

	for (int i = 0; i < n; i++) {
		D[i][i] = 0;
	}

	for (int b = 0; b < n; b++) {
		for (int a = 0; a < n; a++) if (D[a][b] != LLONG_MAX) {
			for (int c = 0; c < n; c++) if (D[b][c] != LLONG_MAX) {
				D[a][c] = min(D[a][c], D[a][b] + D[b][c]);
			}
		}
	}

	vector<vector<int>> Dp((1 << n), vector<int>(n, LLONG_MAX));
	Dp[(1 << 0)][0] = 0;	

	for (int mask = 0; mask < (1 << n); mask++) {
		for (int u = 0; u < n; u++) if (mask >> u & 1) {
			for (int v = 0; v < n; v++) if ((mask >> v & 1) ^ 1) {
				int mask_ = mask | (1 << v);
				if (Dp[mask][u] != LLONG_MAX and D[u][v] != LLONG_MAX) {
					Dp[mask_][v] = min(Dp[mask_][v], Dp[mask][u] + D[u][v]);
				}
			}
		}
	}

	int res = LLONG_MAX;
	for (int u = 1; u < n; u++) if (D[u][0] != LLONG_MAX and Dp[(1 << n) - 1][u] != LLONG_MAX) {
		res = min(res, Dp[(1 << n) - 1][u] + D[u][0]);
	}
	if (res == LLONG_MAX) res = -1;
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

