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

vector<bool> vis;
vector<vector<int>> g;

void dfs(int u)
{
	vis[u] = true;
	for (int v : g[u])
		if (!vis[v]) dfs(v);
}

int main()
{
    _;

	int c, f; cin >> c >> f;
	vis.resize(c);
	g.resize(c);
	while (f--)
	{
		int a, b; cin >> a >> b; a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int comp = 0;
	for (int i = 0; i < c; i++)
		if (!vis[i]) 
		{
			comp++;
			dfs(i);
		}

	cout << comp << endl;
    
    return(0);
}
