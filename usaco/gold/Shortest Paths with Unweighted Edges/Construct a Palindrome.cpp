#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;
	
	vector G(n, vector<vector<int>>(26));
	vector M(n, vector<int>(n, 0));
	for (int i = 0, u, v; i < m; i++) {
		char c; cin >> u >> v >> c; u--, v--;
		G[u][c-'a'].push_back(v);
		G[v][c-'a'].push_back(u);
		M[u][v] = M[v][u] = 1;
	}

	queue<array<int, 2>> Q; Q.push({0, n-1});
	vector D(n, vector<int>(n, INT_MAX));
	D[0][n-1] = 0;

	while (Q.size()) {
		auto [a, b] = Q.front(); Q.pop();

		for (int i = 0; i < 26; i++) {
			for (int c : G[a][i]) {
				for (int d : G[b][i]) if (D[c][d] == INT_MAX) {
					D[c][d] = D[a][b] + 1;
					Q.push({c, d});
				}
			}
		}
	}

	int res = INT_MAX;
	for (int i = 0; i < n; i++) if (D[i][i] != INT_MAX) {
		res = min(res, 2 * D[i][i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (D[i][j] < INT_MAX and M[i][j]) {
				res = min(res, 2 * D[i][j] + 1);
			}
		}
	}

	if (res == INT_MAX) return cout << -1 << endl, 0;
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

