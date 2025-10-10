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
	int n, m; cin >> n >> m;

	vector<vector<pair<int, int>>> g(n);
	vector<tuple<int, int, int>> ed(m);
	for (auto& [a, b, d] : ed) {
		cin >> a >> b >> d; a--, b--;

		g[a].emplace_back(b, d);
		g[b].emplace_back(a, -d);
	}

	vector<ll> pos(n, 0), vis(n, 0);
	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;

		for (auto [v, d] : g[u]) {
			if (vis[v]) continue;
			pos[v] = pos[u] + d;
			dfs(v);
		}
	};

	for (int i = 0; i < n; i++) {
		if (!vis[i]) dfs(i);
	}

	for (auto& [a, b, d] : ed) {
		if (pos[a] + d != pos[b]) return cout << "NO" << endl, 0;
	}
	cout << "YES" << endl;
	
	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
