#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, km; cin >> n >> km;
	string S; cin >> S;

	vector<vector<int>> D(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int agr = 0;
			auto d = [](char a, char b) { return min(abs(a - b), 26 - abs(a - b)); };
			for (int l = i, r = j; l < r; l++, r--) {
				agr += d(S[l], S[r]);
			}
			D[i][j] = agr;
		}
	}

	vector dp(n+1, vector<int>(km+1, INT_MAX));
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 1; k <= km; k++) if (dp[j][k-1] != INT_MAX) {
				dp[i][k] = min(dp[i][k], dp[j][k-1] + D[j][i-1]);
			}
		}
	}

	cout << *min_element(all(dp[n])) << endl;

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

