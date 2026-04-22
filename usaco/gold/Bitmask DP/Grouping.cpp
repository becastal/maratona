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
	vector<vector<int>> A(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}

	vector<int> C(1 << n);
	for (int mask = 0; mask < (1 << n); mask++) {
		for (int a = 0; a < n; a++) if (mask >> a & 1) {
			for (int b = a + 1; b < n; b++) if (mask >> b & 1) {
				C[mask] += A[a][b];
			}
		}
	}
	
	vector<int> dp(1 << n, -1);
	for (int mask = 0; mask < (1 << n); mask++) {
		dp[mask] = C[mask];
		for (int sub = mask; sub; sub = (sub - 1) & mask) {
			dp[mask] = max(dp[mask], C[sub] + dp[mask ^ sub]);	
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

