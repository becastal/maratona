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

void bfs(int ori)
{
	queue<int> q;
	q.push(ori);
	pai[ori] = ori;
	vis[ori] = true;
	
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (auto v : g[u])
			if (!vis[v])
			{
				q.push(v);
				vis[v] = true;
				pai[v] = u;
			}
	}
}

vector<int> cam(int u)
{
	vector<int> res;
	while (pai[u] != -1)
	{
		res.push_back(u);
		if (u == pai[u]) break;
		else u = pai[u];
	}
	reverse(res.begin(), res.end());
	return res;
}

int main()
{
    _;

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

	bfs(0);
	auto res = cam(n-1);

	if (res.empty())
		cout << "IMPOSSIBLE" << endl;
	else
	{
		cout << res.size() << endl;
		for (auto u : res)
			cout << u + 1 << ' ';
		cout << endl;
	}
    
    return(0);
}
