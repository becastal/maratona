#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int dp[100][100];
int solve() {
	int n = (int)A.size();

	dp[0][0] = A[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < (int)A[i].size(); j++) {
			for (int k : {0, -1}) {
				if (j + k >= 0) {
					dp[i][j] = max(dp[i][j], dp[i-1][j + k] + A[i][j]);
				}
			}
		}
	}

	int res = INT_MIN;
	for (int i = 0; i < 100; i++) {
		res = max(res, dp[n-1][i]);
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

