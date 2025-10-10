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

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int t = 0;
	vector<pair<int, int>> res;
	vector<int> vis(n, 0), impar(n, 0);
	function<void(int, int)> dfs = [&](int u, int p) {
		vis[u] = ++t;

		for (int v : g[u]) {
			if (v == p) continue;

			if (!vis[v]) {
				dfs(v, u);
				if (impar[v]) {
					res.emplace_back(v, u);
					impar[v] = 0;
				} else {
					res.emplace_back(u, v);
					impar[u] ^= 1;
				}
			} else if (vis[u] > vis[v]) {
				res.emplace_back(u, v);
				impar[u] ^= 1;
			}
		}
	};
	
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		dfs(i, -1);
	}


	if (count(impar.begin(), impar.end(), 1)) return cout << "IMPOSSIBLE" << endl, 0;
	for (auto [u, v] : res) {
		cout << u + 1 << ' ' << v + 1 << endl;
	}

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
