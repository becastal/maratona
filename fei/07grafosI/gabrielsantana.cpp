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

void solve(int n, int m) {
	vector<vector<int>> g(n);	
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; u--, v--;
		
		g[u].push_back(v);
		g[v].push_back(u);
	}

	
	int res = 0;
	vector<int> visitado(n, 0);
	function<void(int)> dfs = [&](int u) {
		visitado[u] = 1;
		res++;

		for (int v : g[u]) {
			if (!visitado[v]) {
				dfs(v);
			}
		}
	};
	
	int vert; cin >> vert; vert--;
	dfs(vert);
	cout << res << endl;
}

int main()
{
    _;

	int n, m; 
	while (cin >> n >> m) {
		solve(n, m);
	}
    
    return(0);
}
