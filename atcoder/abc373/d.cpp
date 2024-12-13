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

	// aresta u -> v peso w
	// dar um peso pra u e pra v tal que v - u = w pra toda aresta

	int n, m; cin >> n >> m;
	vector<vector<pair<int, int>>> g(n);
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, -w);
	}

	vector<ll> vis(n, 0), x(n, 0);
	function<void(int)> dfs = [&] (int u) {
		vis[u] = 1;
		
		for (auto [v, w] : g[u]) {
			if (!vis[v]) {
				x[v] = x[u] + w;
				dfs(v);
			}
		}
	};

	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			dfs(i);	
		}
	}

	for (ll i : x) cout << i << ' '; cout << endl;

    return(0);
}
