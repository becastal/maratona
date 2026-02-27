#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, a, b; cin >> n >> a >> b;
	double p = 1.0 / (b - a + 1);
	vector<double> dp(n + 1);
	cout << fixed << setprecision(13);

	if (!a) {
		double s = 0;
		for (int i = 1; i <= n; i++) {
			s += dp[i - 1];
			if (i - b - 1 >= 0) s -= dp[i - b - 1];
			dp[i] = (1 + p * s) / (1.0 - p);
		}
		cout << dp[n] << endl;
		return 0;
	}

	double s = 0;
	for (int i = 1; i <= n; i++) {
		if (i - a >= 0) s += dp[i - a];
		if (i - b - 1 >= 0) s -= dp[i - b - 1];
		dp[i] = (1.0 + s * p);
	}
	cout << dp[n] << endl;

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

