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

	
	vector<int> d(n, 0), ciclo(n, INF);
	int n, m; cin >> n >> m;

	vector<vector<int>> g(n);
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		g[u].push_back(v);	
		g[v].push_back(u);	
	}

	vector<int> vis(n);
	function<void(int, int, int)> dfs = [&](int i, int pai, int w) {
		
	};
	dfs(0, -1, 0);
    
    return(0);
}
