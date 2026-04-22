#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int mod = 1e9+7;
int solve() {
	int n; cin >> n;
	vector<vector<int>> A(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}

	vector<int> dp(1 << n);
	dp[0] = 1;
	for (int mask = 0; mask < (1 << n) - 1; mask++) {
		int u = __builtin_popcount(mask);
		for (int i = 0; i < n; i++) if (A[u][i] and mask >> i & 1 ^ 1) {
			int mask_ = mask | (1 << i);
			dp[mask_] += dp[mask];
			if (dp[mask_] >= mod) {
				dp[mask_] -= mod;
			}
		}
	}
	cout << dp[(1 << n) - 1] << endl;

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

