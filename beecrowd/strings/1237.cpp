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

const ll P = 69420;
const ll M = 1e9+9;

int main()
{
    _;

	string a, b;
	while (getline(cin, a) and getline(cin, b)) {
		int n = (int)a.size(), m = (int)b.size();
		vector<vector<int>> dp(n+1, vector<int>(m+1));

		int res = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = (a[i-1] == b[j-1] ? dp[i-1][j-1]+1 : 0);
				res = max(res, dp[i][j]);
			}
		}
		cout << res << endl;
	}
    
    return(0);
}
