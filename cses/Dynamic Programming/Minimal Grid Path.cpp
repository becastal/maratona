#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	vector<string> A(n);
	for (auto& i : A) cin >> i;

	vector dp(n+1, vector<string>(n+1, "["));
	dp[1][0] = dp[0][1] = "";

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + A[i-1][j-1];
		}
	}

	cout << dp[n][n] << endl;

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

