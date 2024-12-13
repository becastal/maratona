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
	string name = "planting";
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);

	int n; cin >> n;
	vector<vector<int>> g(n);

	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v; u--, v--;	

		g[u].push_back(v);
		g[v].push_back(u);
	}

	int res = 0;
	vector<int> vis(n, 0);
	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;

		res = max(res, (int)g[u].size());
		for (int v : g[u]) {
			if (vis[v]) continue;
			dfs(v);
		}
	};

	dfs(0);
	cout << res + 1 << endl;

    return(0);
}
