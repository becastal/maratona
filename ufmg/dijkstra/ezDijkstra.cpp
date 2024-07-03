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
typedef pair<int, int> ii;
typedef vector<vector<ii>> grafo;

int n, m;
grafo g;

int dijkstra(grafo& g, int ori, int dest)
{
	priority_queue<ii> pq;
	pq.push({-0, ori});
	vector<int> dist(n, INF);
	dist[ori] = 0;

	while (!pq.empty())
	{
		int w = -pq.top().f;
		int u = pq.top().s;
		pq.pop();
		if (u == dest)
			return w;

		if (dist[u] < w)
			continue;

		dist[u] = w;
		for (auto [v, wv] : g[u])
		{
			if(dist[v] > w + wv)
			{
				dist[v] = w + wv;
				pq.push({-dist[v], v});
			}
		}
	}
	return INF;
}

void solve()
{
	g = grafo(n);
	for (int i = 0; i < m; i++)
	{
		int a, b, w; cin >> a >> b >> w; a--, b--;
		g[a].push_back({b, w});
	}

	int a, b; cin >> a >> b; a--, b--;
	int d = dijkstra(g, a, b);

	cout << (d == INF ? "NO" : to_string(d)) << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;
		solve();
	}

    return(0);
}
