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

vector<vector<int>> g;
vector<int> gatos;
int n, m, res = 0;

void dfs(int u, int pai, int c)
{
	if (gatos[u])
		c++;
	else
		c = 0;

	if (c > m) return;

	bool folha = true;
	for (int v : g[u])
		if (v != pai)
		{
			folha = false;
			dfs(v, u, c);
		}

	if (folha and c <= m)
		res++;
}

int main()
{
    _;

	cin >> n >> m; 
	g.resize(n);
	gatos.resize(n);

	for (int i = 0; i < n; i++)
		cin >> gatos[i];

	for (int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(0, -1, 0);

	cout << res << endl;
    
    return(0);
}
