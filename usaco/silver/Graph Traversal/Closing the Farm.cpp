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
	setIO("closing");

	int n, m; cin >> n >> m;
	vector<vector<int>> g(n);

	set<int> liv;
	for (int i = 0; i < n; i++) liv.emplace(i);
	vector<int> vis(n, 0), hab(n, 1);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;
		for (int v : g[u]) {
			if (vis[v] or !hab[v]) continue;
			dfs(v);
		}
	};

	function<int()> f = [&]() {
		fill(vis.begin(), vis.end(), 0);
		dfs(*liv.begin());

		int ok = 1;
		for (int j = 0; j < n; j++) {
			if (hab[j]) ok &= vis[j];	
		}

		return ok;
	};
	
	cout << (f() ? "YES" : "NO") << endl;
	for (int i = 0, u; i < n; i++) {
		cin >> u; u--;
		if (i == n-1) return(0);

		hab[u] = 0, liv.erase(u);
		cout << (f() ? "YES" : "NO") << endl;
	}

    return(0);
}
