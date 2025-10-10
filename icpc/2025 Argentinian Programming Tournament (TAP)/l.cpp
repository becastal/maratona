#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, g; cin >> n >> g;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	vector<ll> P(n+1, 0);
	for (int i = 1; i <= n; i++) {
		P[i] = P[i-1] + A[i-1];
	}

	auto W = [&](int l, int r) {
		return g - (P[r] - P[l-1]);
	};

	int m = ceil((sqrtl(1.0 + 8.0*n) - 1.0) / 2.0);
	vector dp(n+1, vector<ll>(m+1, LLONG_MIN));
	dp[0][0] = 0;

	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i-1];
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i][j], dp[i][j-1]);
			if (i - j + 1 >= 1 and dp[i-j][j-1] != LLONG_MIN) {
				dp[i][j] = max(dp[i][j], dp[i-j][j-1] + W(i-j+1, i));
			}
		}
	}

	ll res = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			res = max(res, dp[i][j]);
		}
	}
	cout << res << endl;

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

