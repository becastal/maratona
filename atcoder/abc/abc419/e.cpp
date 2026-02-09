#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m, l; cin >> n >> m >> l;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	int nn = n - l + 1;
	vector<int> falta(max(1, nn));

	int s = 0;
	for (int i = 0; i < l; i++) {
		s = (s + A[i]) % m;
	}
	falta[0] = (m - s) % m;
	for (int i = l, j = 1; i < n; i++, j++) { 
		s = (s - A[i-l] + m) % m;
		s = (s + A[i]) % m;
		falta[j] = (m - s) % m;
	}

	vector<int> dif(max(1, nn), 0);
	for (int i = 0; i < nn - 1; i++) {
		dif[i] = (falta[i+1] - falta[i] + m) % m;
	}

	vector<int> off(n, 0);
	for (int i = 0; i < l; i++) {
		for (int j = i + l; j < n; j += l) {
			off[j] = (off[j - l] + dif[j - l]) % m;
		}
	}

	int ss = 0;
	for (int i = 0; i < l; i++) {
		ss = (ss + off[i]) % m;
	}
	ss = (falta[0] - ss + m) % m;

	vector<vector<int>> G(l);
	for (int i = 0; i < l; i++) {
		for (int j = i; j < n; j += l) {
			G[i].push_back(j);
		}
	}

	vector<vector<int>> P(l, vector<int>(m, 0));
	for (int i = 0; i < l; i++) {
		for (int b = 0; b < m; b++) {
			int agr = 0;
			for (int p : G[i]) agr += (b + off[p]) % m;
			P[i][b] = agr;
		}
	}

	vector<vector<int>> dp(l+1, vector<int>(m, INT_MAX));
	dp[0][0] = 0;
	for (int i = 1; i <= l; i++) {
		for (int r = 0; r < m; r++) if (dp[i-1][r] != INT_MAX) {
			for (int b = 0; b < m; b++) {
				int r_ = (r + b) % m;
				dp[i][r_] = min(dp[i][r_], dp[i-1][r] + P[i-1][b]);
			}
		}
	}
	cout << dp[l][ss] << endl;

	return 0;
}

int main()
{
    _;

	int t = 1;
	while (t--) {
		solve();
	}
    
    return(0);
}
