#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<vector<int>> D(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			cin >> D[i][j];
			D[j][i] = D[i][j];
		}
	}

	vector<ll> dp(1 << n, 0);
	for (int mask = 0; mask < (1 << n) - 1; mask++) {
		int a;
		for (a = 0; mask >> a & 1; a++);

		for (int i = 0; i < n; i++) if (!(mask >> i & 1)) {
			int mask_ = mask | (1 << a) | (1 << i);
			dp[mask_] = max(dp[mask_], dp[mask] + D[a][i]);
		}
	}
	cout << *max_element(all(dp)) << endl;

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

