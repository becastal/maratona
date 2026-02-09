#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
	quase certeza que eh fazer isso virar recorr linear
*/

int solve() {
	int n, m; cin >> n >> m;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	vector<int> dp(m+1);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		vector<int> dp_ = dp;
		for (int j = A[i]; j <= m; j++) {
			dp_[j] += dp_[j - A[i]];
		}
		dp = move(dp_);
	}

	cout << accumulate(all(dp), 0) << endl;

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

