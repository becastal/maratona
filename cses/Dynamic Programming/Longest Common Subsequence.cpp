#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
 
int solve() {
	int n, m; cin >> n >> m;
	vector<int> A(n), B(m);
	for (int& i : A) cin >> i;
	for (int& i : B) cin >> i;
 
	vector dp(n+1, vector<int>(m+1, 0));
	vector pai(n+1, vector<array<int, 2>>(m+1, {-1, -1}));
 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (A[i-1] == B[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
				pai[i][j] = {i-1, j-1};
			} else {
				auto [i_, j_] = (dp[i-1][j] > dp[i][j-1] ? pair<int, int>(i-1, j) : pair<int, int>(i, j-1));
				dp[i][j] = dp[i_][j_];
				pai[i][j] = {i_, j_};
			}
		}
	}
 
	vector<int> R;
	for (int ai = n, aj = m, ult = dp[n][m]+1; ai > 0;) {
		auto [pi, pj] = pai[ai][aj];
 
		if (pi == ai-1 and pj == aj-1) R.push_back(A[ai-1]);
		if (pi <= 0) break;
		ai = pi, aj = pj;
	}
 
	cout << dp[n][m] << endl;
	reverse(all(R));
	for (int i : R) cout << i << ' '; cout << endl;
 
 
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
