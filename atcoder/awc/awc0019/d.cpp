#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m, t, res = 0, add = 0; cin >> n >> m >> t;

	vector<int> dp(m + 1, LLONG_MIN);
	dp[0] = 0;

	for (int i = 0, a, b, c; i < n; i++) {
		cin >> a >> b >> c;
		if (b >= t) {
			res += a;
		} else {
			for (int j = m; j >= c; j--) if (dp[j-c] != LLONG_MIN) {
				dp[j] = max(dp[j], dp[j-c] + a);
				add = max(add, dp[j]);
			}
		}
	}
	cout << res + add << endl;

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

