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

	const int mod = 1e9 + 7;
	int n, m; cin >> n >> m;
	vector g(n, vector<int>()), dp((1 << n), vector<int>(n, 0));	

	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[v].push_back(u);
	}
    
	dp[1][0] = 1;
	for (int mask = 0; mask < (1 << n); mask++) {
		if (__builtin_popcount(mask) <= 1) continue;

		// tem que ter o primeiro vertice
		if (mask & 1 ^ 1) continue;

		// so posso considerar os subsets com a ultima cidade se tiver todas as outras antes
		if ((mask & (1 << (n - 1))) and mask != ((1 << n) - 1)) continue;

		for (int i = 0; i < n; i++) if (mask & (1 << i)) {
			for (int j : g[i]) if (mask & (1 << j)) {
				dp[mask][i] = (dp[mask][i] + dp[mask ^ (1 << i)][j]) % mod;
			}
		}
	}

	cout << dp[(1 << n)-1][n-1] << endl;

    return(0);
}
