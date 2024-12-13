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
	int n, m, k, y;
	cin >> n >> m >> k >> y; y--;

	vector<int> deg(n, 0);
	vector<vector<pair<int, int>>> g1(n), g2(n);
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w; u--, v--;
		g1[u].emplace_back(v, w);
		g2[v].emplace_back(u, w);
		deg[v]++;
	}

	// se tiver um loop que retorna pro y, eu sempre consigo.

	vector<int> vis(n, 0);
	function<int(int)> dfs1 = [&] (int u) {
		vis[u] = 1;

		int res = 0;
		for (auto [v, w] : g1[u]) {
			if (!vis[v]) {
				res |= dfs1(v);
			} else {
				res |= (v == y);
			}
		}
		return res;
	};

	if (dfs1(y)) return cout << "YES" << endl, 0;

	// agora eh uma arvore	
	// com raiz em y, ver se tem uma descida que tem peso >= k
	vector<ll> d(n, -1); d[y] = 0;
	fill(vis.begin(), vis.end(), 0);
	function<int(int)> dfs2 = [&] (int u) {
		vis[u] = 1;

		for (auto [v, w] : g2[u]) {
			if (d[v] != -1) d[v] = LINF;
			d[v] = max(d[v], d[u] + w);

			if (!vis[v]) dfs2(v);
		}
		return 1;
	};
	
	dfs2(y);
	if ((ll)*max_element(d.begin(), d.end()) >= (ll)k) return cout << "YES" << endl, 0;
	
	cout << "NO" << endl;
	return 0;
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
