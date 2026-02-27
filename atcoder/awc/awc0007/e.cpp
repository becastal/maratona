#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m, s, t; cin >> n >> m >> s >> t;

	vector<int> P(m);
	for (int& i : P) {
		cin >> i;
	}
	P.insert(P.begin(), s);
	m++;

	auto dist = [&](int a, int b) {
		a--, b--;
		return (abs(a / n - b / n) + abs(a % n - b % n));
	};
	if (m == 1) return cout << dist(s, t) << endl, 0;

	vector<vector<int>> D(m, vector<int>(m));
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			D[j][i] = D[i][j] = dist(P[i], P[j]);
		}
	}

	vector<vector<int>> dp((1 << m), vector<int>(m + 1, LLONG_MAX));
	dp[1][0] = 0;	

	for (int mask = 1; mask < (1 << m); mask++) {
		for (int u = 0; u < m; u++) if (mask >> u & 1 and dp[mask][u] != LLONG_MAX) {
			for (int v = 0; v < m; v++) if (!(mask >> v & 1)) {
				int mask_ = mask | (1 << v);
				dp[mask_][v] = min(dp[mask_][v], dp[mask][u] + D[u][v]);
			}
		}
	}

	int res = LLONG_MAX;
	for (int i = 1; i < m; i++) {
		res = min(res, dp[(1 << m) - 1][i] + dist(P[i], t));
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

