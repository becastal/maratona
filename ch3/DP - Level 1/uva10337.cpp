#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

void solve() {
	int n = 10, m; cin >> m; m/=100;

	vector<vector<int>> w(n, vector<int>(m));
	for (auto& l : w) for (auto& c : l) cin >> c;

	vector<vector<int>> dp(n, vector<int>(m+1, INF));
	dp[n-1][0] = 0;

	for (int j = 1; j <= m; j++) {
		for (int i = 0; i < n; i++) {
			dp[i][j] = min(dp[i][j], dp[i][j-1] + 30 - w[i][j-1]);
			if (i) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 20 - w[i-1][j-1]);
			if (i < n-1) dp[i][j] = min(dp[i][j], dp[i+1][j-1] + 60 - w[i+1][j-1]);
		}
	}

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j <= m; j++) {
	//		cout << setw(5) << (dp[i][j] == INF ? -1 : dp[i][j]) << ' ';	
	//	}
	//	cout << endl;
	//}

	cout << dp[n-1][m] << endl << endl;;
}

int main()
{
    _;

	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		//if (t) cout << endl;
		solve();
	}
    
    return(0);
}
