#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m; cin >> n >> m;
	vector<int> A(n), B(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i];
	}

	vector<vector<int>> dp(n + 1, vector<int> (m + 1, LLONG_MIN));
	dp[0][0] = 0;

	for (int i = 1; i <= n; i++) {
		auto [a, b] = tie(A[i-1], B[i-1]);
		dp[i] = dp[i-1];
		for (int j = m; j >= a; j--) if (dp[i-1][j-a] != LLONG_MIN) {
			dp[i][j] = max(dp[i][j], dp[i-1][j-a] + b);
		}
	}

	vector<vector<int>> vis(n + 1, vector<int> (m + 1));
	vector<int> R(n + 1);
	function<void(int, int)> dfs = [&](int ui, int uj) {
		if (!ui) return;
		if (vis[ui][uj]) return;
		vis[ui][uj] = 1;	

		auto [a, b] = tie(A[ui-1], B[ui-1]);
		if (dp[ui-1][uj] == dp[ui][uj]) {
			dfs(ui-1, uj);
		}
		if (uj >= a and dp[ui-1][uj - a] + b == dp[ui][uj]) {
			R[ui] = 1;
			dfs(ui-1, uj-a);
		}
	};

	int mx = *max_element(all(dp[n]));
	for (int j = 1; j <= m; j++) if (dp[n][j] == mx) {
		dfs(n, j);
	}

	for (int i = 1; i <= n; i++) {
		cout << (R[i] ? "Yes" : "No") << endl;
	}

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

