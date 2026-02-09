#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
knapsack dboa
*/

int solve() {
	int n; cin >> n;

	vector<int> X(n), Y(n), Z(n);
	vector<int> W(n), V(n);

	for (int i = 0; i < n; i++) {
		cin >> X[i] >> Y[i] >> Z[i];

		V[i] = max(0, (Y[i] + X[i] + 1) / 2 - X[i] );
		W[i] = Z[i];
	}
	int s = accumulate(all(Z), 0);

	vector<ll> dp(s + 1, LLONG_MAX);
	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = s; j >= W[i]; j--) if (dp[j - W[i]] != LLONG_MAX) {
			dp[j] = min(dp[j], dp[j - W[i]] + V[i]);
		}
	}

	ll res = LLONG_MAX;
	for (int i = (s + 1) / 2; i <= s; i++) {
		res = min(res, dp[i]);
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

