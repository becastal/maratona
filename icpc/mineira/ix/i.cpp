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

	for (int i = 0; i < n; i++) {
		A.push_back(A[i]);
	}

	auto calc = [&](int l) -> ll {
		vector<int> B(n);
		for (int i = 0, j = l; i < n; i++, j++) {
			B[i] = A[j];
		}

		vector<ll> dp(n+1, 0);
		for (int i = 1; i <= n; i++) {
			dp[i] = max(dp[i-1], (i > 1 ? dp[i-2] : 0) + B[i-1]);
		}

		return dp[n];
	};

	ll res = 0;
	for (int i = 0; i < n; i++) {
		res = max(res, calc(i));
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

