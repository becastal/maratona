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
	int n, q; cin >> n >> q;
	int nn = __lg(n) + 1;

	vector<vector<int>> pai(n, vector<int>(nn, -1)), g(n);
	vector<int> d(n, 0);
	for (int i = 1, pi; i < n; i++) {
		cin >> pi; pi--;
		g[pi].push_back(i);
		g[i].push_back(pi);
	}

	function<void(int, int)> dfs = [&](int u, int p) {
		pai[u][0] = p;
		for (int v : g[u]) {
			if (v == p) continue;
			d[v] = d[u] + 1;
			dfs(v, u);
		}
	};
	dfs(0, -1);

	for (int j = 1; j < nn; j++) {
		for (int u = 0; u < n; u++) {
			int pu = pai[u][j-1];
			pai[u][j] = (pu == -1 ? -1 : pai[pu][j-1]);
		}
	}

	auto lca = [&](int u, int v) {
		if (d[u] < d[v]) swap(u, v);

		int diff = d[u] - d[v];
		for (int j = 0; j < nn; j++) {
			if (diff & (1 << j)) {
				u = pai[u][j];
			}
		}
		if (u == v) return u;

		for (int j = nn-1; j >= 0; j--) {
			if (pai[u][j] != pai[v][j]) {
				u = pai[u][j];
				v = pai[v][j];
			}
		}

		return pai[u][0];
	};

	while (q--) {
		int u, v; cin >> u >> v; u--, v--;
		cout << lca(u, v) + 1 << endl;
	}

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
