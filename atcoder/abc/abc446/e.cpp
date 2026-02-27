#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int m, a, b; cin >> m >> a >> b;

	vector<vector<int>> G(m * m), G_(m * m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			int i_ = j, j_ = (a * j + b * i) % m;

			int u = i * m + j, v = i_ * m + j_;
			G[u].push_back(v);
			G_[v].push_back(u);
		}
	}

	vector<int> vis(m * m);
	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;
		for (int v : G_[u]) if (!vis[v]) {
			dfs(v);
		}
	};
	for (int k = 0; k < m; k++) {
		// (0, k) e (k, 0)

		int u1 = 0 * m + k;
		int u2 = k * m + 0;
		if (!vis[u1]) dfs(u1);
		if (!vis[u2]) dfs(u2);
	}

	int ruim = 0;
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < m; j++) {
			ruim += (vis[i * m + j]);
		}
	}
	cout << (m - 1) * (m - 1) - ruim << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

