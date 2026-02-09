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

	int n; cin >> n;
	vector<int> v(n);
	for (int& i : v) cin >> i;

	vector<vector<ll>> dp(n, vector<ll>(2,0));
	dp[0][0] = 0, dp[0][1] = v[0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 1; j++) {
			dp[i][j] = max(dp[i-1][j^1] + (j^1 ? 2*v[i] : v[i]), dp[i-1][j]);
		}
	}

	cout << max(dp[n-1][0], dp[n-1][1]) << endl;
    
    return(0);
}
