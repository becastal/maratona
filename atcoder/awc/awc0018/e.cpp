#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

/*

10 5 20
3 500  
2 100  !
5 300
1 200  !
4 800
2 600
3 150  !
6 900  !
1 700
5 1000 !

*/

int solve() {
	int n, k, b, res = 0; cin >> n >> k >> b;
	vector<int> C(n+1), S(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> C[i] >> S[i];
	}

	vector dp(n+1, vector<int>(k + 1, LLONG_MAX));
	dp[0][0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) if (S[j] < S[i]) {
			for (int ii = 1; ii <= k; ii++) if (dp[j][ii-1] != LLONG_MAX) {
				dp[i][ii] = min(dp[i][ii], dp[j][ii-1] + C[i]);
				if (dp[i][ii] <= b) {
					res = max(res, ii);
				}
			}
		}
	}
	cout << res << endl;

	//vector dp(n + 1, vector(b + 1, vector<int>(k + 1, LLONG_MIN)));
	//dp[0][0][0] = 0;

	//stack<array<int, 2>> St;
	//for (int i = 0, c, s; i < n; i++) {
	//	cin >> c >> s;
	//	while (St.size() and St.top()[1] > s) {
	//		St.pop();
	//	}
	//	int j = (St.size() ? St.top()[0] : -1) + 1;
	//	St.push({i, s});

	//	dp[i+1] = dp[j];
	//	for (int ii = 1; ii <= k; ii++) {
	//		for (int jj = b; jj >= c; jj--) {
	//			dp[i+1][jj][ii] = max(dp[i+1][jj][ii], dp[j][jj - c][ii - 1] + 1);
	//			res = max(res, dp[i+1][jj][ii]);
	//		}
	//	}
	//}
	//cout << res << endl;

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

