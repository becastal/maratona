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

const int mod = 9901;

void solve() {
	int n, k; cin >> n >> k;
	vector<vector<int>> d(n, vector<int>(n, 1));

	for (int i = 0, u, v; i < k; i++) {
		cin >> u >> v; u--, v--;
		d[u][v] = d[v][u] = 0;	
	}

	for (int i = 0; i < n; i++) {
		d[i][i] = 0;
	}

	vector<vector<ll>> dp((1 << n), vector<ll>(n, 0));
	dp[1][0] = 1;

	for (int i = 1; i < (1 << n); i++) {
		for (int u = 0; u < n; u++) {
			if (!(i & (1 << u))) continue;

			for (int v = 0; v < n; v++) {
				if (i & (1 << v) or !d[u][v]) continue;

				int ni = i | (1 << v);
				dp[ni][v] = (dp[ni][v] + dp[i][u]) % mod;
			}
		}
	}

	ll res = 0;
	for (int i = 1; i < n; i++) {
		if (d[0][i]) res = (res + dp[(1 << n)-1][i]) % mod;
	}
	cout << (res * 4951) % mod << endl;
}

int main()
{
    _;

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
    
    return(0);
}
