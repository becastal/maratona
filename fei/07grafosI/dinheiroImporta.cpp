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
	vector<int> valor(n), vis(n, 0);

	for (int& i : valor) cin >> i;
	
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	auto dfs = [&] (int i) {
		stack<int> s; s.push(i);
		vis[i] = 1;

		ll total = 0;
		while (s.size()) {
			int u = s.top(); s.pop();
			total += valor[u];

			for (int v : g[u]) {
				if (!vis[v]) {
					s.push(v);
					vis[v] = 1;
				}
			}
		}

		return !total;
	};

	int ok = 1;
	for (int i = 0; i < n and ok; i++) {
		if (!vis[i]) {
			ok &= dfs(i);
		}
	}

	cout << (ok ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    
    return(0);
}
