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

int main()
{
    _;

	int n, m; cin >> n >> m;
	vector<vector<int>> g(n);
	vector<int> vis(n, 0);

	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	function<void(int)> dfs = [&] (int u) {
		vis[u] = 1;

		for (int v : g[u]) {
			if (!vis[v]) {
				dfs(v);
			}
		}
	};

	vector<int> comps;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			comps.push_back(i);
			dfs(i);
		}
	}

	vector<pair<int, int>> con;
	for (int i = 1; i < (int)comps.size(); i++) {
		con.emplace_back(comps[i], comps[i-1]);
	}

	cout << con.size() << endl;
	for (auto [a, b] : con) {
		cout << a + 1 << ' ' << b + 1 << endl;
	}
    
    return(0);
}
