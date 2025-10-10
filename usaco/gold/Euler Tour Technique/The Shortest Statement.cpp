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

int solve() {
	int n, m; cin >> n >> m;
	vector<vector<array<int, 2>>> G(n);
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}

	int mm = __lg(n) + 1;
	vector<vector<int>> pai(n, vector<int>(mm, 0));
	vector<int> vis(n, 0), D(n, 0), sobra;
	vector<ll> W(n, 0);
	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;
		for (auto [v, w] : G[u]) {
			if (vis[v]) {
				if (v != pai[u][0]) sobra.push_back(v);
			} else {
				W[v] = W[u] + w;
				D[v] = D[u] + 1;
				pai[v][0] = u;
				dfs(v);
			}
		}
	};
	dfs(0);

	for (int j = 1; j < mm; j++) {
		for (int i = 0; i < n; i++) {
			pai[i][j] = pai[pai[i][j-1]][j-1];
		}
	}
	
	auto kth = [&](int u, int k) {
		for (int i = 0; i < mm; i++) if (k >> i & 1) {
			u = pai[u][i];
		}
		return u;
	};

	auto lca = [&](int a, int b) {
		if (D[b] > D[a]) swap(a, b);	

		a = kth(a, D[a] - D[b]);
		if (a == b) return a;

		for (int i = mm-1; i >= 0; i--) {
			if (pai[a][i] != pai[b][i]) {
				a = pai[a][i];
				b = pai[b][i];
			}
		}
		return pai[a][0];
	};

	function<vector<ll>(int)> dijkstra = [&](int u) {
		vector<ll> Dis(n, LINF); Dis[u] = 0;
		priority_queue<pair<ll, int>> pq; pq.emplace(0, u);

		while (pq.size()) {
			auto [udist, u] = pq.top(); pq.pop();
			if (-udist > Dis[u]) continue;

			for (auto [v, w] : G[u]) {
				if (Dis[v] > Dis[u] + w) {
					Dis[v] = Dis[u] + w;
					pq.emplace(-Dis[v], v);
				}
			}
		}
		return Dis;
	};
	sort(all(sobra));
	sobra.erase(unique(all(sobra)), sobra.end());
	vector<vector<ll>> Ds;

	for (int u : sobra) {
		Ds.push_back(dijkstra(u));	
	}

	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b; a--, b--;

		ll res = W[a] + W[b] - 2 * W[lca(a, b)];
		for (auto& Dij : Ds) {
			res = min(res, Dij[a] + Dij[b]);
		}
		cout << res << endl;
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
