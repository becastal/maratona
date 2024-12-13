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
typedef pair<int, int> ii;

int main()
{
    _;

	int n, m; cin >> n >> m;
	map<ii, int> M;
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w;
		int a = min(u, v), b = max(u, v);
		if (M.count(ii(a, b))) M[ii(a, b)] = min(M[ii(a, b)], w);
		else M[ii(a, b)] = w;
	}

	vector<vector<ii>> g(n);
	for (auto [v, w] : M) {
		g[v.f].push_back(ii(v.s, w));
		g[v.s].push_back(ii(v.f, w));
	}
	
	
	auto dijkstra = [&] (int src) {
		vector<int> d(n, INF); d[src] = 0;	priority_queue<pair<int, int>> pq;
		pq.emplace(0, src);

		int res = -INF;
		while (!pq.empty()) {
			auto [nd, u] = pq.top(); pq.pop();
			if (-nd > d[u]) continue;

			res = max(res, d[u]);
			for (auto [idx, w] : g[u]) if (d[idx] > d[u] + w) {
				d[idx] = d[u] + w;
				pq.emplace(-d[idx], idx);
			}
		}

		return res;
	};

	int res = INF;
	for (int i = 0; i < n; i++) {
		res = min(res, dijkstra(i));
	}
	cout << res << endl;
    
    return(0);
}
