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

const int mod = 998244353;

int main()
{
    _;

	int n; cin >> n;
	vector dp(n+1, vector<ll>(10, 0));

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}
	
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= 9; j++) {
			dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
			if (j > 1) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
			if (j < 9) dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % mod;
		}
	}

	ll res = 0;
	for (int i = 1; i <= 9; i++) {
		res = (res + dp[n][i]) % mod;
	}
	cout << res << endl;
    
    return(0);
}
