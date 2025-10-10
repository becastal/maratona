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
	setIO("milkvisits");

	int n, m; cin >> n >> m;
	string s; cin >> s;

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int cc = 0;
	vector<int> vis(n, 0), comp(n);
	function<void(int)> dfs = [&](int u) {
		vis[u] = 1, comp[u] = cc;

		for (int v : g[u]) {
			if (vis[v] or s[u] != s[v]) continue;
			dfs(v);
		}
	};

	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		dfs(i);
		cc++;
	}

	vector<int> res(m);
	for (int i = 0; i < m; i++) {
		int u, v; char c;
		cin >> u >> v >> c; u--, v--;
		res[i] = (comp[u] != comp[v]) or (c == s[u]);
	}
	for (int i : res) cout << i; cout << endl;

    return(0);
}
