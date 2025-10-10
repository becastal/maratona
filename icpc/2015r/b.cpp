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

	int n, c; cin >> n >> c;
	vector<int> v(n);
	for (int& i : v) cin >> i;

	vector<vector<int>> dp(n+1, vector<int>(2, 0));
	for (int i = 0; i <= n; i++) dp[i][1] = -INF;

	for (int i = 1; i <= n; i++) {
		dp[i][0] = max(dp[i-1][0], dp[i-1][1] + v[i-1]);
		dp[i][1] = max(dp[i-1][1], dp[i-1][0] - v[i-1] - c);
	}

	cout << dp[n][0] << endl;
    
    return(0);
}
