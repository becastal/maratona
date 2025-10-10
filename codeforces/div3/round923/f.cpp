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
	vector<int> disc(n, -1), low(n, -1), ruim(m, 0);
	int t = 0;

	vector<vector<tuple<int, int, int>>> g(n);
	vector<tuple<int, int, int, int>> ed(m);
	for (int i = 0; i < m; i++) {
		auto& [w, u, v, ii] = ed[i];
		cin >> u >> v >> w; u--, v--; ii = i;
		g[u].emplace_back(v, w, i);
		g[v].emplace_back(u, w, i);
	}

	function<void(int, int)> dfs1 = [&](int u, int p) {
		disc[u] = low[u] = ++t;

		for (auto [v, w, idx] : g[u]) {
			if (v == p) continue;
			if (disc[v] == -1) {
				dfs1(v, u);
				low[u] = min(low[u], low[v]);
				if (low[v] > disc[u]) ruim[idx] = 1;
			} else {
				low[u] = min(low[u], disc[v]);
			}
		}
	};

	for (int i = 0; i < n; i++) {
		if (disc[i] == -1) dfs1(i, -1);
	}	

	int a = -1, b = -1, minw_idx = -1, minw = INF;
	sort(ed.begin(), ed.end());	
	for (auto [w, u, v, idx] : ed) {
		if (!ruim[idx]) {
			a = u, b = v, minw_idx = idx, minw = w;	
			break;
		}
	}

	vector<int> pai(n, -1), vis(n, 0), res;
	function<void(int, int)> dfs2 = [&](int u, int p) {
		vis[u] = 1;
		for (auto [v, w, idx] : g[u]) {
			if (vis[v] or idx == minw_idx) continue;
			dfs2(v, pai[v] = u);
		}
	};

	vis[a] = 1;
	dfs2(a, -1);
	for (int u = b; u != -1; u = pai[u]) {
		res.push_back(u+1);
	}

	cout << minw << ' ' << res.size() << endl;
	for (int i : res) cout << i << ' '; cout << endl;
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
