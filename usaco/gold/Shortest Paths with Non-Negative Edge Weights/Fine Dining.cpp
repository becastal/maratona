#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m, k; cin >> n >> m >> k;

	vector<vector<array<int, 2>>> G(n);
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}

	vector<int> D(n, LLONG_MAX); D[n-1] = 0;
	priority_queue<array<int, 2>> Pq; Pq.push({0, n-1});

	while (Pq.size()) {
		auto [du, u] = Pq.top(); Pq.pop();
		if (-du != D[u]) continue;

		for (auto [v, w] : G[u]) if (D[v] > D[u] + w) {
			D[v] = D[u] + w;
			Pq.push({-D[v], v});
		}
	}

	priority_queue<array<int, 2>> Pqk;

	while (Pqk.size()) {
		auto [duk, u] = Pqk.top(); Pqk.pop();
		if (-duk < 0 or -duk != Dk[u]) continue;

		for (auto [v, w] : G[u]) if (Dk[v] < Dk[u] - w) {
			Dk[v] = Dk[u] - w;
			Pqk.push({-Dk[v], v});
		}
	}

	for (int u = 0; u < n - 1; u++) {
		cout << (Dk[u] >= 0) << endl;
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

