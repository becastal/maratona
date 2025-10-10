#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) cin >> i;
	// dp[i][j]: qual o minimo pro prefixo i tendo usado j segmentos
	// - res ta em dp[n][j], pra todo j
	// - na transicao eu tenho que pagar P[l][r], que eh a quantidade
	//   de diferencas na subarray:
	//   A: A[l], A[l+1], ..., A[r]
	//   B: 0   , 1     , ..., 2
	//   que da pra computar em n^2

	vector<vector<int>> P(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		int dif = 0, agr = 0;
		for (int j = i; j < n; j++) {
			dif += (A[j] != agr++);
			P[i][j] = dif;
		}
	}

	//for (int i = 0; i < n; i++) {
	//	for (int j = i; j < n; j++) {
	//		printf("(%d, %d): %d\n", i, j, P[i][j]);
	//	}
	//}

	vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			for (int k = n; k >= 1; k--) if (dp[j][k-1] != INT_MAX) {
				dp[i][k] = min(dp[i][k], dp[j][k-1] + P[j][i-1]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << dp[n][i] << endl;
	}

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main() {
    _;
	setIO("taming");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}
