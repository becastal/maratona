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
	int n, m; cin >> n >> m;
	if (m == n-1) return cout << 1 << endl, 0;

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int res = 0;
	vector<int> vis(n, 0), pai(n, -1), d(n, 0);
	function<void(int)> dfs = [&] (int u) {
		vis[u] = 1;

		for (int v : g[u]) {
			if (!vis[v]) {
				pai[v] = u;
				d[v] = d[u] + 1;
				dfs(v);
			} else {
				if (v == pai[u]) continue;
				if (d[v] > d[u]) continue;		
				res++;
			}
		}
	};
	dfs(0);

	cout << (unsigned ll)pow(3, res) << endl;
	return 0;
}

int main()
{
    _;

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case " << t << ": ";
		solve();
	}
    
    return(0);
}
