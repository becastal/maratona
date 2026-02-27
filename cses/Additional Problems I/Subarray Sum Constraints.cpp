#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m; cin >> n >> m;

	vector<vector<array<int, 2>>> G(n + 1);
	for (int i = 0, a, b, s; i < m; i++) {
		cin >> a >> b >> s; a--;
		G[a].push_back({b, s});
		G[b].push_back({a, -s});

		// P[b] - P[a - 1] = s
		// P[b] = s + P[a - 1];
	}

	vector<int> P(n + 1, 0), vis(n + 1, 0);
	function<int(int)> dfs = [&](int u) {
		vis[u] = 1;

		for (auto [v, s] : G[u]) {
			if (vis[v]) {
				if (P[u] + s != P[v]) return 0;
			} else {
				P[v] = P[u] + s;
				if (!dfs(v)) return 0;
			}
		}
		return 1;
	};

	for (int u = 0; u <= n; u++) if (!vis[u]) {
		if (!dfs(u)) return cout << "NO" << endl, 0;
	}

	cout << "YES" << endl;
	for (int i = 0; i < n; i++) {
		cout << P[i + 1] - P[i] << " \n"[i==n-1];
	}

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

