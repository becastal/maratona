#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m, k; cin >> n >> m >> k;

	vector<array<int, 2>> A(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> A[i][j];
		}
	}

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = max(0LL, i - k); j < i; j++) {
			auto [a, b] = A[i-1];
			for (int w = 0; w + b <= m; w++) {
				dp[i][w] = max(dp[i][w], dp[j][w + b] + a);
				res = max(res, dp[i][w]);
			}
		}
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

