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

vector<vector<int>> C(51, vector<int>(51));

void solve() {
	// dp[i][j] de quantos jeitos da pra somar i usando j valores
	// eu ganho em todos os dp[t][n] e ele ganha nos outros m escolhe n - dp[t][n] jogos

	int m; cin >> m;
	vector<int> v(m);
	for (int& i : v) cin >> i;

	int n, t; cin >> n >> t;
	vector<vector<int>> dp(t+1, vector<int>(n+1, 0));
	dp[0][0] = 1;

	for (int i : v) {
		for (int j = t; j >= i; j--) {
			for (int k = 1; k <= n; k++) {
				dp[j][k] += dp[j-i][k-1];
			}
		}
	}

	cout << dp[t][n] << " : " << C[m][n] - dp[t][n] << endl;
}

int main()
{
    _;

	for (int i = 0; i <= 50; i++) {
		C[i][0] = C[i][i] = 1;
	}

	for (int i = 1; i <= 50; i++) {
		for (int j = 1; j < i; j++) {
			C[i][j] = C[i-1][j-1] + C[i-1][j];	
		}
	}

	int t; cin >> t;
	for (int T = 1; T <= t; T++) {
		cout << "Game " << T << " -- ";
		solve();
	}
    
    return(0);
}
