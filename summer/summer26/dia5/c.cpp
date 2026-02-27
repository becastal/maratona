#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MAX = 101;

int solve() {
	int n, m = 1; cin >> n;

	vector<array<int, 2>> A(n);
	for (auto& [a, b] : A) {
		cin >> a >> b;
		m = max({m, a, b});
	}
	
	vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));
	vector<int> vis(5 * m);

	for (int i = 1, t = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++, t++) {
			if (i == j) continue;

			for (int k = 1; k < i; k++) if (k != j) {
				vis[dp[k][j]] = t;
			}

			for (int k = 1; k < j; k++) if (i != k) {
				vis[dp[i][k]] = t;
			}

			for (int k = 1; k < min(i, j); k++) if (i != j) {
				vis[dp[i - k][j - k]] = t;
			}

			int mex = 0;
			while (vis[mex] == t) {
				mex++;	
			}
			dp[i][j] = mex;
		}
	}

	//for (int i = 0; i <= m; i++) {
	//	for (int j = 0; j <= m; j++) {
	//		cout << dp[i][j] << " \n"[j==m];
	//	}
	//}

	int res = 0;
	for (auto [a, b] : A) {
		if (a == b) return cout << "Y" << endl, 0;
		res ^= dp[a][b];
	}
	cout << (res ? "Y" : "N") << endl;


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

