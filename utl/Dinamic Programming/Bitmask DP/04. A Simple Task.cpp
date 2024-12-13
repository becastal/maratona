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
	vector g(n, vector<ll>(n, 0)), dp((1 << n), vector<ll>(n, 0));

	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[u][v] = g[v][u] = 1;
	}

	for (int i = 0; i < n; i++) {
		dp[1 << i][i] = 1;
	}

	ll res = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		if (__builtin_popcount(mask) <= 1) continue;
		int primeiro = __builtin_ctz(mask);
		
		for (int i = 0; i < n; i++) if (mask & (1 << i) and i != primeiro) {
			for (int j = 0; j < n; j++) if (g[j][i]) {
				dp[mask][i] += dp[mask ^ (1 << i)][j];
			}
			if (__builtin_popcount(mask) >= 3 and g[primeiro][i]) {
				res += dp[mask][i];
			}
		}
	}

	cout << res / 2 << endl;

    return(0);
}
