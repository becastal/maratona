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

void solve() {
	int n, m; cin >> n >> m;
	vector<int> cor(n);
	for (int& i : cor) cin >> i;

	vector<vector<int>> adj(n, vector<int>(n, 0));
	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		adj[u][v] = 1, adj[v][u] = 1;
		g[u].push_back(v), g[v].push_back(u);
	}

	vector<vector<int>> d(n, vector<int>(n, INF));	
	auto bfs = [&]() {
		queue<pair<int, int>> q; q.emplace(0, n-1);
		d[0][n-1] = 0;

		while (q.size()) {
			auto [a, b] = q.front(); q.pop();

			for (int i : g[a]) {
				for (int j : g[b]) {
					if (d[i][j] == INF and cor[i] != cor[j]) {
						d[i][j] = d[a][b] + 1;
						q.emplace(i, j);
					}
				}
			}
		}

		return d[n-1][0] != INF ? d[n-1][0] : -1;
	};

	cout << bfs() << endl;	
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
