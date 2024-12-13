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

int main()
{
    _;

	int n, m; cin >> n >> m;
	vector<vector<int>> dp(n, vector<int>(m, -INF));
	vector<vector<char>> M(n, vector<char>(m));
	for (auto& l : M) for (auto& c : l) cin >> c;
	
	for (int i = 0; i < n; i++) {
		dp[i][0] = (M[i][0] == '0' ? 4 : -INF);
	}
	for (int i = 0; i < m; i++) {
		dp[0][i] = (M[0][i] == '0' ? 4 : -INF);
	}
	
	for (int x1 = 0; x1 < n; x1++) {
		for (int y1 = 0; y1 < m; y1++) {
			for (int x2 = 1; x2 < n; x2++) {
				for (int y2 = 1; y2 < m; y2++) {
					
				}
			}
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			res = max(res, dp[i][j]);
		}
	}
	cout << res << endl;
    
    return(0);
}
