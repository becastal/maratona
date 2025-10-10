#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m, in, out; cin >> n >> m >> in >> out;
	in--, out--;
	vector<vector<array<int, 2>>> G(n);
	
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}

	auto dijkstra = [&](int ig) {
		priority_queue<pair<ll, int>> pq; pq.emplace(0, in);	
		vector<ll> D(n, LLONG_MAX); D[in] = 0;

		while (pq.size()) {
			auto [du, u] = pq.top(); pq.pop();
			if (-du > D[u]) continue;

			for (auto [v, w] : G[u]) if (v != ig and D[v] > D[u] + w) {
				D[v] = D[u] + w;
				pq.emplace(-D[v], v);
			}
		}
		return D;
	};

	vector<ll> Da = dijkstra(-1), Db = dijkstra(out);

	vector<int> R;
	for (int u = 0; u < n; u++) {
		if (Da[u] == 2 * Da[out] and Db[u] != 2 * Da[out]) {
			R.push_back(u);
		}
	}

	if (R.empty()) return cout << "*" << endl, 0;
	for (int i : R) cout << i + 1 << ' '; cout << endl;

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

