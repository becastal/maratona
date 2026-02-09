#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	vector<int> X(n), Y(n);
	for (int i = 0; i < n; i++) {
		cin >> X[i] >> Y[i];
	}

	vector<ll> dp(2, 0);
	for (int i = 0; i < n; i++) {
		auto dp_ = dp;
		if (X[i]) {
			dp_[1] = max(dp_[1], dp[0] + Y[i]);
		} else {
			dp_[0] = max(dp_[0], max(dp[0], dp[1]) + Y[i]);
		}
		dp = move(dp_);
	}
	cout << max(dp[0], dp[1]) << endl;

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

