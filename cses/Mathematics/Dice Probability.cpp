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

int solve() {
	int n, a, b; cin >> n >> a >> b;

	vector<vector<double>> dp(n+1, vector<double>(6 * n + 10, 0));
	dp[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6; j++) {
			for (int ii = j; ii <= 6*n; ii++) {
				dp[i][ii] += dp[i-1][ii-j];
			}
		}
	}

	double s = 0.0;
	for (int i = a; i <= b; i++) {
		s += dp[n][i];
	}
	cout << fixed << setprecision(6) << s / pow(6, n) << endl;

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
