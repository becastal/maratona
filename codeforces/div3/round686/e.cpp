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
	int n; cin >> n;
	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < n; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int uu = -1, vv = -1;
	vector<int> vis(n, 0);
	function<void(int)> dfs1 = [&](int u) {
		vis[u] = 1;	
		for (int v : g[u]) {
			if (!vis[v]) dfs1(v);
			else {
				uu = u, vv = v;
			}
		}
	};
	dfs1(0);

	vector<int> pai(n, -1);
	function<void(int, int)> dfs2 = [&](int u, int p) {
		for (int v : g[u]) {
			if (v == p or (u == uu and v == vv) or (u == vv and v == uu)) continue;
			dfs2(v, pai[v] = u);
		}
	};
	dfs2(uu, -1);

	int tam = 1;
	for (int i = vv; i != -1; i = pai[i]) {
		tam++;	
	}
	dbg(tam);
	tam = 1;
	
	cout << ((ll)n * (n - 1) / 2) + ((ll)tam * (tam - 1) / 2) << endl;
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
