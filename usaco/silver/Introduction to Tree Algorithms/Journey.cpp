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

int solve() {
	int n; cin >> n;

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	double res = 0;
	function<void(int, int, int, double)> dfs = [&](int u, int p, int d, double prob) {
		int fil = g[u].size() - (u ? 1 : 0);

		for (int v : g[u]) {
			if (v == p) continue;	
			dfs(v, u, d + 1, prob / fil);
		}

		if (!fil) res += prob * d;
	};
	dfs(0, -1, 0, 1.0);

	cout << fixed << setprecision(12) << res << endl;

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
