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

void solve(int n, int m) {
	int in, out; cin >> in >> out;
	vector<tuple<int, int, int>> a1(m);
	vector<vector<pair<int, int>>> g1(n);

	vector<vector<int>> d_floyd(n, vector<int>(n, INF));

	for (int i = 0; i < n; i++) d_floyd[i][i] = 0;

	for (auto& [u, v, w] : a1) {
		cin >> u >> v >> w;
		g1[u].emplace_back(v, w);
		d_floyd[u][v] = min(d_floyd[u][v], w);
	}

	auto dijkstra = [&](vector<vector<pair<int, int>>>& g) {
		priority_queue<pair<int, int>> pq;
		pq.emplace(0, in);
		vector<int> d(n, INF);	
		d[in] = 0;

		while (pq.size()) {
			auto [ndist, u] = pq.top(); pq.pop();
			if (-ndist > d[u]) continue;

			for (auto [v, w] : g[u]) if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				pq.emplace(-d[v], v);
			}
		}

		return d;
	};

	auto floyd_warshall = [&](vector<vector<int>>& d) {
		for (int c = 0; c < n; c++) {
			for (int a = 0; a < n; a++) {
				for (int b = 0; b < n; b++) {
					d[a][b] = min(d[a][b], d[a][c] + d[c][b]);
				}
			}
		}
	};

	floyd_warshall(d_floyd);

	vector<vector<pair<int, int>>> g2(n);
	for (auto [u, v, w] : a1) {
		if (d_floyd[in][u] + w + d_floyd[v][out] == d_floyd[in][out]) continue;		
		g2[u].emplace_back(v, w);
	}

	int res = dijkstra(g2)[out];
	cout << (res == INF ? -1LL : res) << endl;
}

int main()
{
    _;

	int n, m;
	while (cin >> n >> m and n and m) {
		solve(n, m);
	}
    
    return(0);
}
