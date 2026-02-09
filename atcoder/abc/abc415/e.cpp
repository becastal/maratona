#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	// bb + dp
	int n, m; cin >> n >> m;
	vector<vector<int>> A(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
		}
	}
	vector<int> P(n+m-1);
	for (int& i : P) cin >> i;

	auto da = [&](ll x) {
		// dp[i][j] eh o maximo do caminho ate (i, j), sendo que respeitei
		// 			que nenhum passo ate agora tinha valores negativo.
		vector<vector<ll>> dp(n, vector<ll>(m, -1));
		
		dp[0][0] = x + A[0][0] - P[0];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				vector<pair<int, int>> mov;
				if (i) mov.emplace_back(i-1, j);
				if (j) mov.emplace_back(i, j-1);

				for (auto [ii, jj] : mov) if (dp[ii][jj] >= 0) {
					dp[i][j] = max(dp[i][j], dp[ii][jj] + A[i][j] - P[i + j]);
				}
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				//if (x == 2) cout << dp[i][j] << " \n"[j == m-1];
				if (i+j+1 == n+m-1 and dp[i][j] >= 0) return 1;	
			}
		}
		return 0;
	};

	ll l = 0, r = (ll)1e15+10, res = r;
	while (l <= r) {
		ll mid = l + (r - l) / 2;

		if (da(mid)) {
			res = mid;
			r = mid-1;
		} else {
			l = mid+1;
		}
	}
	cout << res << endl;

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
