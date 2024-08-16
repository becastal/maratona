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
	vector<int> gatos(n);

	for (int& i : gatos) cin >> i;
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v; u--, v--;	
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int res = 0;
	function<void(int, int, int)> dfs = [&](int u, int pai, int c) {
		if (gatos[u]) c++;
		else c = 0;

		if (c > m) return;
		bool folha = 1;
		for (int v : g[u]) {
			if (v != pai) {
				folha = 0;
				dfs(v, u, c);
			}
		}

		if (folha and c <= m) res++;
	};

	dfs(0, -1, 0);
	cout << res << endl;
    
    return(0);
}
