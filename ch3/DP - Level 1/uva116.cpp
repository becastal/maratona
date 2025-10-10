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

void solve(int n, int m) {
	vector<vector<int>> a(n, vector<int>(m)), dp(n, vector<int>(m, INF)), pai(n, vector<int>(m, INF));
	
	for (auto& l : a) for (auto& c : l) cin >> c;

	for (int i = 0; i < n; i++) {
		dp[i][m-1] = a[i][m-1];
	}

	for (int j = m-2; j >= 0; j--) {
		for (int i = 0; i < n; i++) {
			for (int d : {-1, 0, +1}) {
				int ii = (i + d + n) % n;
				if (dp[ii][j+1] + a[i][j] < dp[i][j] or 
				   (dp[ii][j+1] + a[i][j] == dp[i][j] and ii < pai[i][j])) {
					dp[i][j] = dp[ii][j+1] + a[i][j];
					pai[i][j] = ii;
				}
			}
		}
	}

	int agr = -1, total = INF;
	for (int i = 0; i < n; i++) {
		if (dp[i][0] < total) {
			agr = i;
			total = dp[i][0];
		}
	}

	vector<int> res(m);
	for (int j = 0; j < m; j++) {
		res[j] = agr+1;
		agr = pai[agr][j];
	}
	
	for (int i = 0; i < m; i++) {
		cout << res[i] << " \n"[i==m-1];
	}
	cout << total << endl;
}

int main()
{
    _;

	int n, m; 
	while (cin >> n >> m) {
		solve(n, m);
	}
    
    return(0);
}

