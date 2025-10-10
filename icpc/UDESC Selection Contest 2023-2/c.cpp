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

int solve() {
	int n, m, d; cin >> n >> m >> d;
	vector<int> c(n, 0);
	for (int i = 0, x; i < d; i++) {
		cin >> x; c[--x] = 1;
	}

	vector<vector<pair<int, int>>> g(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[u].emplace_back(v, c[v]);
		g[v].emplace_back(u, c[u]);
	}

	auto dijkstra = [&]() {
		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
		vector<pair<int, int>> d(n, {INF, INF});

		pq.emplace(0, 0, 0); d[0] = pair<int, int>(0, 0);
		while (pq.size()) {
			auto [dua, dub, u] = pq.top(); pq.pop();
			if (pair<int, int>(dua, dub) > d[u]) continue;

			for (auto [v, w] : g[u]) {
				if (pair<int, int>(dua + w, dub + 1) >= d[v]) continue;
				d[v] = pair<int, int>(dua + w, dub + 1);
				pq.emplace(d[v].f, d[v].s, v);
			}
		}
		return d[n-1];
	};

	auto res = dijkstra();
	cout << res.f + c[0] << ' ' << res.s << endl;

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
