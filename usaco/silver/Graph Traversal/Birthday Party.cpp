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

int solve(int n, int m) {
	vector<vector<int>> g(n);
	vector<pair<int, int>> ar(m);
	
	for (auto& [u, v] : ar) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> vis(n, 0);
	function<void(int, int)> dfs = [&](int u, int v_) {
		vis[u] = 1;
		for (int v : g[u]) {
			if (vis[v] or v_ == v) continue;
			dfs(v, -1);
		}
	};

	int ok = 1;
	for (auto& [u, v] : ar) {
		fill(vis.begin(), vis.end(), 0);
		dfs(u, v);
		ok &= vis[v];
	}
	cout << (ok ? "No" : "Yes") << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	int n, m;
	while (cin >> n >> m and (n or m)) {
		solve(n, m);
	}
    
    return(0);
}
