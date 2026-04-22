#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, s, t; cin >> n >> s >> t;

	vector<vector<int>> Dp(s + 1, vector<int>(n + 1, LLONG_MIN));
	Dp[0][0] = 0;

	for (int i = 0, p, c, w; i < n; i++) {
		cin >> p >> c >> w;		

		for (int j = s; j >= w; j--) {
			for (int k = 1; k <= n; k++) if (Dp[j - w][k - 1] != LLONG_MIN) {
				Dp[j][k] = max(Dp[j][k], Dp[j-w][k-1] + (p - c));
			}
		}
	}

	int res = LLONG_MAX;
	for (int i = 0; i <= s; i++) {
		for (int j = 1; j <= n; j++) if (Dp[i][j] >= t) {
			res = min(res, j);	
		}
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

