#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MOD = 1e9+7;

int solve() {
	string S; cin >> S;
	int n = (int)S.size();

	vector<int> dp(n + 1, 0), ult(26, 0);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = ((2 * dp[i-1] - (ult[S[i-1]-'a'] ? dp[ult[S[i-1]-'a'] - 1] : 0) % MOD) + MOD) % MOD;
		ult[S[i-1]-'a'] = i;
	}
	cout << (dp[n] - 1 + MOD) % MOD << endl;

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

