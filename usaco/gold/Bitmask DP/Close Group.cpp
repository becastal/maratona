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
	int n, m; cin >> n >> m;

	vector<pair<int, int>> A(n);
	vector<vector<int>> M(n, vector<int>(n));
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		M[u][v] = M[v][u] = 1;
	}

	vector<int> dp(1 << n, INF);
	vector<int> conectado(1 << n, 0);
	for (int mask = 0; mask < (1 << n); mask++) {
		vector<int> V;
		for (int j = 0; j < n; j++) {
			if (mask & (1 << j)) V.push_back(j);
		}

		int ok = 1;
		for (int j = 0; j < (int)V.size(); j++) {
			for (int jj = j+1; jj < (int)V.size(); jj++) {
				ok &= M[V[j]][V[jj]];
			}
		}
		conectado[mask] = ok;
		if (ok) dp[mask] = 1;
	}

	dp[0] = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		for (int submask = mask; submask; submask = (submask-1) & mask) {
			int subset = mask ^ submask;

			if (dp[subset] != INF and dp[submask] != INF) {
				dp[mask] = min(dp[mask], dp[subset] + dp[submask]);
			}
		}
	}
	cout << dp[(1 << n) - 1] << endl;

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
