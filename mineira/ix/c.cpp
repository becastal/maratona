#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	ll res = 0;
	vector<ll> dp(2, 0), dp_(2, 0);
	for (int i = 1; i <= n; i++) {
		dp_[0] = max(dp[1], dp[0]);
		dp_[1] = A[i-1] + dp[0];
		dp = dp_;
		res = max({res, dp[0], dp[1]});
	}
	cout <<  res << endl;

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

