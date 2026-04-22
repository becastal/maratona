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
vector<bool> vis;
vector<int> pai;
int ciclos = 0;

int dfs(int u)
{
	stack<int> s;
	s.push(u);
	int ciclos = 0;
	vis[u] = true;
	pai[u] = -1;

	while (!s.empty())
	{
		int u = s.top(); s.pop();
		for (auto v : g[u])
		{
			if (!vis[v])
			{
				s.push(v);
				vis[v] = true;
				pai[v] = u;
			}
			else if (v != pai[u])
				ciclos++;
		}
	}

	ciclos /= 2;
	return ciclos;
}

int main()
{
    _;
	// pra ser um cthulu, ele so pode ter apenas um ciclo e deve ser conexo;

	int n, m; cin >> n >> m;
	g.resize(n);
	vis.assign(n, false);
	pai.assign(n, -1);

	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	bool umciclo = (dfs(0) == 1);
	bool conexo = true;
	for (int i = 0; i < n; i++)
		if (!vis[i])
		{
			conexo = false;
			break;
		}

	cout << (conexo and umciclo ? "FHTAGN!" : "NO") << endl;
    
    return(0);
}
