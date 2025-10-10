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
	int n, a, b; cin >> n >> a >> b; a--, b--;
	
	vector<vector<pair<int, int>>> g(n);
	for (int i = 0, u, v, w; i < n-1; i++) {
		cin >> u >> v >> w; u--, v--;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}

	auto dfs = [&](auto dfs, vector<int>& d, int u, int p, int aa) {
		if (aa and u == b) return;

		for (auto [v, w] : g[u]) {
			if (d[v] != -1 or v == p) continue;
			d[v] = d[u] ^ w;
			dfs(dfs, d, v, u, aa);
		}
	};

	vector<int> da(n, -1), db(n, -1);
	da[a] = 0, db[b] = 0;
	dfs(dfs, da, a, -1, 1);
	dfs(dfs, db, b, -1, 0);

	set<int> sb;
	for (int i = 0; i < n; i++) {
		if (i == b) continue;
		sb.insert(db[i]);
	}

	int ok = 0;
	for (int i = 0; i < n; i++) {
		if (i == b) continue;
		ok |= sb.count(da[i]);
	}
	
	cout << (!da[b] or ok ? "YES" : "NO") << endl;
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
