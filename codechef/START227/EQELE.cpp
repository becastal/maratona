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
	
	vector<int> dp(n + 1), ocor(n, -1);
	for (int i = 0, x; i < n; i++) {
		dp[i+1] = dp[i];
		cin >> x; x--;

		if (ocor[x] == -1) {
			ocor[x] = i;
		} else {
			dp[i+1] = max(dp[i+1], dp[ocor[x]] + 1);
			ocor[x] = i;
		}
	}
	cout << 2 * *max_element(all(dp)) << endl;

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

