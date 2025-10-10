#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main()
{
    _;

	vector<vector<vector<ll>>> dp(66, vector<vector<ll>>(66, vector<ll>(2, 0)));
	dp[1][1][1] = dp[1][0][0] = 1;

	for (int i = 2; i <= 65; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
			dp[i][j][1] = dp[i-1][j][0] + (j ? dp[i-1][j-1][1] : 0);
		}
	}

	int n, s; 
	while (cin >> n >> s and n != -1) {
		cout << dp[n][s][0] + dp[n][s][1] << endl;

	}
    
    return(0);
}
