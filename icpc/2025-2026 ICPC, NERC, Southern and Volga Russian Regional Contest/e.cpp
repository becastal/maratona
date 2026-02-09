#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m, k; cin >> n >> m >> k;

	vector<string> A(n);
	for (auto& i : A) cin >> i;

	vector<vector<int>> P(n+1, vector<int>(m, 0)), vis(n, vector<int>(m, 0));
	for (int j = 0; j < m; j++) {
		for (int i = 1; i <= n; i++) {
			P[i][j] = P[i-1][j] + (A[i-1][j] == 'x');
		}
	}

	auto valido = [&](int i, int j) {
		if (i < 0 or j < 0 or i >= n or j >= m or i + k > n or vis[i][j]) return 0;
		if (P[i + k][j] - P[i][j] > 0) return 0;
		return 1;
	};

	int res = 0;
	function<void(int, int)> dfs = [&](int i, int j) {
		vis[i][j] = 1;
		res = max(res, i + k);

		if (valido(i, j - 1)) dfs(i, j - 1);	
		if (valido(i, j + 1)) dfs(i, j + 1);	
		if (valido(i + 1, j)) dfs(i + 1, j);	
	};
	dfs(0, 0);

//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cout << vis[i][j] << " \n"[j == m-1];
//		}
//	}
//
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

