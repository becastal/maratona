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
vector<int> d;

void bfs(int s)
{
	d = vector<int> (g.size(), INF);
	queue<int> q;
	q.push(s);
	d[s] = 0;

	while (!q.empty())
	{
		int u = q.front(); q.pop();
		
		for (auto v : g[u])
			if (d[v] == INF)
			{
				d[v] = d[u] + 1;
				q.push(v);
			}
	}
}

int main()
{
    _;

	int t; cin >> t;
	while (t--)
	{
		int n, m; cin >> n >> m;	
		g = vector<vector<int>>(n);
		// sei la como fazer com dfs. com bfs faz mais sentido a partir da paridade da distancia da origem.

		for (int i = 0; i < m; i++) {
			int u, v; cin >> u >> v; u--, v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		bfs(0);
		vector<int> par, imp;
		for (int i = 0; i < n; i++) {
			if (d[i] & 1) imp.push_back(i);
			else par.push_back(i);
		}

		if (par.size() < imp.size()) {
			cout << par.size() << endl;
			for (auto v : par) cout << v + 1 << ' ';
		}
		else {
			cout << imp.size() << endl;
			for (auto v : imp) cout << v + 1 << ' ';
		}
		cout << endl;
	}
    return(0);
}
