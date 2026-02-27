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
	
	vector<int> F(n + 1);
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		if (x <= n) F[x]++;
	}

	int mex = 0;
	for (; mex <= n and F[mex]; mex++);

	vector<int> dp(mex + 1, LLONG_MAX);
	dp[mex] = 0;
	for (int i = mex - 1; i >= 0; i--) {

		for (int j = i + 1; j <= mex; j++) if (dp[j] != LLONG_MAX) {
			int pi = (F[i] - 1) * j + i;
			dp[i] = min(dp[i], pi + dp[j]);
		}
		//cout << i << ": " << dp[i] << endl;
	}

	cout << dp[0] << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

