#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		A[i] = c - 'a';
	}

	vector<vector<int>> D(m, vector<int>(m));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> D[i][j];
		}
	}

	for (int b = 0; b < m; b++) {
		for (int a = 0; a < m; a++) {
			for (int c = 0; c < m; c++) {
				D[a][c] = min(D[a][c], D[a][b] + D[b][c]);
			}
		}
	}

	vector<vector<int>> P(n+1, vector<int>(m, 0));
	for (int a = 0; a < m; a++) {
		for (int i = 1; i <= n; i++) {
			P[i][a] = P[i-1][a] + (D[A[i-1]][a]);
		}
	}

	vector dp(n+1, vector<int>(m, INT_MAX)), mn(n+1, vector<int>(m, INT_MAX));
	for (int a = 0; a < m; a++) dp[0][a] = mn[0][a] = 0;

	for (int i = 1; i <= n; i++) {
		for (int a = 0; a < m; a++) if (i >= k and mn[i-k][a] != INT_MAX) {
			dp[i][a] = min(dp[i][a], P[i][a] + mn[i-k][a]);
		}

		int melhor = *min_element(all(dp[i]));
		for (int a = 0; a < m; a++) {
			int agr = (melhor == INT_MAX ? INT_MAX : melhor - P[i][a]);
			mn[i][a] = min(mn[i-1][a], agr);
		}
	}

	cout << *min_element(all(dp[n])) << endl;

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main() {
    _;
	setIO("cowmbat");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}
