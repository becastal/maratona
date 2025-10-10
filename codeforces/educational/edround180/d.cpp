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

	vector<int> vis(n, 0);
	vector<vector<int>> g(n);
	vector<pair<int, int>> res;

	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int r = -1;
	for (int i = 0; i < n and r == -1; i++) {
		if (g[i].size() == 2) r = i;
	}

	if (r == -1) return cout << "NO" << endl, 0;

	vis[r] = 1;
	res.emplace_back(r, g[r][0]);
	res.emplace_back(g[r][1], r);


	function<void(int, int)> dfs = [&](int u, int c) {
		vis[u] = 1;

		for (int v : g[u]) {
			if (vis[v]) continue;
			if (c) res.emplace_back(v, u);
			else res.emplace_back(u, v);
			dfs(v, c ^ 1);
		}
	};
	dfs(g[r][0], 1);
	dfs(g[r][1], 0);

	cout << "YES" << endl;
	for (auto [a, b] : res) {
		cout << a + 1 << ' ' << b + 1 << endl;
	}

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
