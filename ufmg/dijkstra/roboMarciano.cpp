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
typedef vector<vector<pair<int, int>>> grafo;
typedef pair<int, int> ii;

int n;

int dijkstra(grafo& g)
{
	priority_queue<ii> pq;
	pq.push({0, n});
	vector<int> dist(n, INF);
	vector<bool> vis(n, false);

	while (!pq.empty())
	{
		int w = -pq.top().f;
		int u = pq.top().s;
		pq.pop();
		if (vis[u])
			continue;

		vis[u] = true;
		for (auto [v, wv] : g[u])
			if(!vis[v])
			{
				dist[v] = w + wv;
				pq.push({-dist[v], v});
			}
	}
	return dist[n + 1];
}

int main()
{
    _;

	ii pi, pf;
	cin >> pi.f >> pi.s >> pf.f >> pf.s;

	cin >> n;
	vector<pair<ii, ii>> r(n);

	for (auto& ri : r)
		cin >> ri.f.f >> ri.f.s >> ri.s.f >> ri.s.s;

	r.push_back({pi, pi});
	r.push_back({pf, pf});

	grafo g(n + 2);
	for (int i = 0; i < n + 1; i++)
		for (int j = i + 1; j < n + 2; j++)
		{
			int dx = max(0, max(r[i].f.f, r[j].f.f) - min(r[i].s.f, r[j].s.f));
			int dy = max(0, max(r[i].f.s, r[j].f.s) - min(r[i].s.s, r[j].s.s));
			int w = dx + dy;
			// printf("d(r[%d], r[%d]) %d\n", i, j, w); 
			g[i].push_back({j, w});
			g[j].push_back({i, w});
		}

	cout << dijkstra(g) << endl;
    
    return(0);
}
