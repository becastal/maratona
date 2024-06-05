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

void dfs(int v)
{
	vis[v] = true;

	for (auto w : g[v]) 
		if (!vis[w])
			dfs(w);
}

int main()
{
    _;

	int n, m; cin >> n >> m;
	g = vector<vector<int>> (n);
	vis = vector<bool> (n);
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int t = 0;
	for (int i = 0; i < n; i++)
		if (!vis[i]) 
		{
			t++;
			dfs(i);
		}

	cout << t << endl;
    
    return(0);
}
