#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m, t; cin >> n >> m >> t; t--;
	vector<vector<array<int, 2>>> G(n);
	for (int i = 0, u, v, w; i < m; i++) { 
		cin >> u >> v >> w; u--, v--;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}

	priority_queue<array<int, 2>> pq; pq.push({0, 0});
	vector<int> D(n, LLONG_MAX); D[0] = 0;
	while (pq.size()) {
		auto [du, u] = pq.top(); pq.pop();
		if (-du != D[u]) continue;

		for (auto [v, w] : G[u]) if (D[v] > D[u] + w) {
			D[v] = D[u] + w;	
			pq.push({-D[v], v});
		}
	}

	if (D[t] == LONG_MAX) return cout << -1 << endl, 0;
	cout << 2 * D[t] << endl;

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

