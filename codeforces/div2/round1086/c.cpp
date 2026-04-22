#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n; cin >> n;
	vector<int> C(n), P(n);
	for (int i = 0; i < n; i++) {
		cin >> C[i] >> P[i];
	}

	vector<double> Dp(n + 1);
	Dp[n] = 0;
	for (int i = n-1; i >= 0; i--) {
		Dp[i] = max(Dp[i+1], C[i] + (1.0 - 1.0 * P[i] / 100.0) * Dp[i+1]);
	}
	cout << fixed << setprecision(10);
	cout << Dp[0] << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

