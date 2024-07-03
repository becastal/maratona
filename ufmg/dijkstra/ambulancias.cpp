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

int n, m, q;
grafo g;

vector<int> dijkstra(grafo& g, vector<int> hosp)
{
	priority_queue<ii> pq;
	vector<int> dist(n, INF);
	for (int amb : hosp)
	{
		pq.push({-0, amb});
		dist[amb] = 0;
	}

	while (!pq.empty())
	{
		int w = -pq.top().f;
		int u = pq.top().s;
		pq.pop();
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
	return dist;
}

void solve()
{
	g = grafo(n);
	for (int i = 0; i < m; i++)
	{
		int a, b, w; cin >> a >> b >> w; a--, b--;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
	}
	vector<int> hosp(q);
	for (int& i : hosp)
	{
		cin >> i;
		i--;
	}

	vector<int> dist = dijkstra(g, hosp);

	int res = -INF;
	for (auto d : dist)
		res = max(res, d);

	cout << res << endl;
}

int main()
{
    _;

	while (cin >> n >> m >> q)
		solve();
    
    return(0);
}
