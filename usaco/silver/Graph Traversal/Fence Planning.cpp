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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("fenceplan");

	int n, m; cin >> n >> m;
	vector<pair<int, int>> pos(n);
	for (auto& [x, y] : pos) cin >> x >> y;

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int xmin, xmax, ymin, ymax;
	vector<int> vis(n, 0);
	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;
		auto [x, y] = pos[u];
		xmin = min(xmin, x), xmax = max(xmax, x);
		ymin = min(ymin, y), ymax = max(ymax, y);
		for (int v : g[u]) {
			if (vis[v]) continue;
			dfs(v);
		}
	};

	int res = INF;
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		xmin = INF, xmax = -INF;
		ymin = INF, ymax = -INF;
		dfs(i);
		res = min(res, 2 * (xmax - xmin) + 2 * (ymax - ymin));
	}
	cout << res << endl;

    return(0);
}
