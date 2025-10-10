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
	vector<vector<pair<int, int>>> g(n);

	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}

	vector<ll> s(n);
	for (ll& i : s) cin >> i;

	auto dij = [&]() {
		vector<vector<ll>> d(n, vector<ll>(1001, LINF)); d[0][s[0]] = 0;
		priority_queue<tuple<ll, ll, int>> pq; // dv, min si do caminho, v
		pq.emplace(0, LINF, 0);

		while (!pq.empty()) {
			auto [du, su, u] = pq.top(); pq.pop();
			su = min(su, s[u]);
			du = -du;

			if (d[u][su] < du) continue;

			for (auto [v, w] : g[u]) {
				ll sv = min(su, s[v]);
				if (d[v][sv] > d[u][su] + w * su) {
					d[v][sv] = d[u][su] + w * su;
					pq.emplace(-d[v][sv], sv, v);
				}
			}
		}
		return *min_element(d[n-1].begin(), d[n-1].end());
	};

	cout << dij() << endl;
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
