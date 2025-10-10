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
typedef pair<int, int> ii;

int main()
{
    _;

	int n; cin >> n;
	vector<vector<int>> g(n);
	vector<vector<int>> M(n, vector<int>(n));
	vector<int> res(n-1, 0);

	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
		M[u][v] = M[v][u] = i;
	}

	vector<int> pai(n), d(n, 0);
	function<void(int, int)> dfs = [&](int u, int p) {
		for (int v : g[u]) {
			if (v == p) continue;
			d[v] = d[u]+1;
			dfs(v, pai[v] = u);
		}
	};

	auto lca = [&](int u, int v) {
        while (d[u] > d[v]) u = pai[u];
        while (d[v] > d[u]) v = pai[v];
        while (u != v) {
            u = pai[u];
            v = pai[v];
        }
        return u;
    };
	dfs(0, -1);

	int m; cin >> m;
	vector<tuple<int, int, int>> ed(m);
	for (auto& [w, u, v] : ed) {
		cin >> u >> v >> w; u--, v--;
	}
	sort(ed.begin(), ed.end());

	for (auto& [w, u, v] : ed) {
		if (d[u] > d[v]) swap(u, v);

		int l = lca(u, v);	
		for (int i = v; i != l; i = pai[i]) {
			res[M[i][pai[i]]] = w;
		}
		for (int i = u; i != l; i = pai[i]) {
			res[M[i][pai[i]]] = w;
		}
	}
	for (int& i : res) if (!i) i = (int)1e6;

	int ok = 1;
	for (auto [w, u, v] : ed) {
		int agr = (int)1e6;
		int l = lca(u, v);
		for (int i = v; i != l; i = pai[i]) {
			agr = min(agr, res[M[i][pai[i]]]);
		}
		for (int i = u; i != l; i = pai[i]) {
			agr = min(agr, res[M[i][pai[i]]]);
		}
		if (w != agr) {
			ok = 0;
			break;
		}
	}

	if (!ok) return cout << -1 << endl, 0;
	for (int i : res) cout << i << ' '; cout << endl;
    
    return(0);
}
