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
	int n, m, k; cin >> n >> m >> k;

	vector<vector<pair<int, int>>> g(n);
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		g[u].emplace_back(v, w);
	}

	vector<multiset<ll>> d(n);
	auto dij = [&]() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				d[i].insert(LINF);
			}
		}
		d[0].insert(0);
		d[0].erase(d[0].find(LINF));
		priority_queue<pair<ll, int>> pq;
		pq.emplace(0, 0);
	 
		while (pq.size()) {
			auto [ndist, u] = pq.top(); pq.pop();
			ll du = -ndist;
			if (du > *d[u].rbegin()) continue;
 
			for (auto [v, w] : g[u]) {
				if (du == LINF or du + w >= *d[v].rbegin()) continue;
				d[v].insert(du + w);
				d[v].erase(d[v].find(*d[v].rbegin()));
				pq.emplace(-(du + w), v);
			}
		}
	};
	dij();

	for (ll i : d[n-1]) cout << i << ' '; cout << endl;

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
