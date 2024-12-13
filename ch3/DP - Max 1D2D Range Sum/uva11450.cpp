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
	int m, c; cin >> m >> c;

	vector<vector<int>> dp(c+1, vector<int>(m+1)), v(c);

	for (int i = 0; i < c; i++) {
		int sz; cin >> sz;
		for (int j = 0; j < sz; j++) {
			int x; cin >> x;
			v[i].push_back(x);
		}
	}

	dp[0][0] = 1;
	for (int i = 1; i <= c; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k : v[i-1]) {
				if (j - k >= 0 and dp[i-1][j-k]) {
					dp[i][j] = 1;
				}
			}
		}
	}

	int res = -1;
	for (int i = m; i >= 0 and res == -1; i--) {
		if (dp[c][i]) res = i;	
	}

	cout << (res == -1 ? "no solution" : to_string(res)) << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
