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

vector<int> dfs(vector<vector<int>>& g, int ori)
{
	vector<int> dist(g.size(), INF), pai(g.size());
	dist[ori] = 0;
	pai[ori] = -1;
	stack<int> s;
	s.push(ori);
	
	int maior = -INF, longe;

	while (!s.empty())
	{
		int u = s.top(); s.pop();
		if (dist[u] > maior)
		{
			maior = dist[u];
			longe = u;
		}

		for (auto v : g[u])
			if (dist[v] == INF)
			{
				s.push(v);
				dist[v] = dist[u] + 1;
				pai[v] = u;
			}
	}

	vector<int> res;
	while (pai[longe] != -1)
	{
		res.push_back(longe);
		longe = pai[longe];
	}

	return res;
}

int main()
{
    _
	// eu acho que o grafo com o menor diametro depois da uniao vai ser sempre o que for a uniao dos
	// dois grafos a partir do meio dos dois diametros de cada grafo.
	// se ele for par talvez seja mais trampo. como sao duas arvores, eh mais facil achar o diametro.
    
	int n, m; cin >> n >> m;
	vector<vector<int>> a(n), b(m);

	for (int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v; u--, v--;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	for (int i = 0; i < m - 1; i++)
	{
		int u, v; cin >> u >> v; u--, v--;
		b[u].push_back(v);
		b[v].push_back(u);
	}

   	vector<int> da = dfs(a, dfs(a, 0).front()),
   	            db = dfs(b, dfs(b, 0).front());
   
   	cout << da[da.size() / 2] + 1 << ' ' << db[db.size() / 2] + 1 << endl;

    return(0);
}
