#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
	pra uma subs s com ca e cA

	-> se eu puder so uma operacao com caps
	eu pago min(ca * x + cA * y, cA * x + ca * y + 2 * z)

*/

int solve() {
	int x, y, z; cin >> x >> y >> z;
	string S; cin >> S;
	int n = (int)S.size();

	vector dp(n+1, vector<ll>(2, LLONG_MAX));
	dp[0][0] = 0;
	dp[0][1] = z;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = min(dp[i][0], dp[i-1][1] + z + (S[i-1] == 'A' ? y : x));
		dp[i][0] = min(dp[i][0], dp[i-1][0] + (S[i-1] == 'A' ? y : x));

		dp[i][1] = min(dp[i][1], dp[i-1][0] + z + (S[i-1] == 'a' ? y : x));
		dp[i][1] = min(dp[i][1], dp[i-1][1] + (S[i-1] == 'a' ? y : x));
	}
	cout << min(dp[n][0], dp[n][1]) << endl;

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

