#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve(int n, int m) {
	vector<vector<array<int, 2>>> G(n);
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}

	vector<int> vis(n, 0), W(n, 0);
	vector<array<int, 2>> pai(n, {-1, -1});
	function<void(int, int)> dfs = [&](int u, int p) {
		vis[u] = 1;
		for (auto [v, w] : G[u]) if (v != p) {
			if (!vis[v]) {
				pai[v] = {u, w};
				dfs(v, u);
			} else if (vis[v] == 1) {
				if (W[v] != 0) continue;
				int soma = w;

				vector<int> cic = {v};
				for (int i = u; i != v; i = pai[i][0]) {
					soma += pai[i][1];
					cic.push_back(i);
				}

				for (int i : cic) W[i] = soma;
			}
		}
		vis[u] = 2;
	};
	for (int i = 0; i < n; i++) if (!vis[i]) {
		dfs(i, -1);
	}

	//for (int i = 0; i < n; i++) {
	//	cout << i + 1 << ' ' << W[i] << endl;
	//}
	auto dijkstra = [&](int in, int mn) {
		vector<int> D(n, INF); D[in] = 0;
		priority_queue<array<int, 2>> pq; pq.push({0, in});

		int res = INF;
		while (pq.size()) {
			auto [du, u] = pq.top(); pq.pop();
			if (-du > D[u]) continue;

			if (W[u] >= mn) res = min(res, 2 * D[u] + W[u]);
			for (auto [v, w] : G[u]) if (D[v] > D[u] + w) {
				D[v] = D[u] + w;
				pq.push({-D[v], v});
			}
		}

		return (res == INF ? -1 : res);
	};

	int q; cin >> q;
	while (q--) {
		int in, mn; cin >> in >> mn; in--;
		cout << dijkstra(in, mn) << endl;
	}

	return(0);
}

int main()
{
    _;

	int n, m;
	while (cin >> n >> m) {
		solve(n, m);
	}
    
    return(0);
}
