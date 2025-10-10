#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int edit(string A, string B) {
	int n = A.size(), m = B.size();
	vector dp(n+1, vector<int>(m+1, (int)1e9));

	for (int i = 0; i <= n; i++) dp[i][0] = i;
	for (int i = 0; i <= m; i++) dp[0][i] = i;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = min({
				dp[i-1][j-1] + (A[i-1] != B[j-1]),
				dp[i-1][j] + 1,
				dp[i][j-1] + 1,
			});
		}
	}
	return dp[n][m];
};

int solve() {
	int n, m = 5; cin >> n;
	vector<int> C(m, 0);
	for (int i = 0; i < n; i++) {
		string S; cin >> S;
		
		vector<int> D(m);
		for (int j = 0; j < m; j++) {
			string A; cin >> A;
			D[j] = edit(S, A);
		}

		int mn = *min_element(all(D));
		for (int j = 0; j < m; j++) if (D[j] == mn) {
			C[j] += (!mn + 1);	
		}
	}

	int mx = *max_element(all(C));
	cout << (mx / 2) << "." << (mx & 1 ? '5' : '0') << endl;

	vector<int> res;
	for (int i = 0; i < m; i++) {
		if (C[i] == mx) {
			res.push_back(i+1);
		}
	}
	for (int i = 0; i < (int)res.size(); i++) {
		cout << res[i] << " \n"[i == (int)res.size()-1];
	}

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

