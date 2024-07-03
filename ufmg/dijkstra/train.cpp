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
typedef vector<vector<tuple<int, int, int>>> grafo;

int n, m, x, y;
vector<int> k;
grafo g;

int dijkstra()
{
	priority_queue<ii> pq;
	pq.push({-0, x});
	vector<int> dist(n, INF);
	dist[x] = 0;

	while (!pq.empty())
	{
		auto [w, u] = pq.top();
		w = -w;
		pq.pop();

		if (dist[u] < w)
			continue;

		for (auto [v, wv, kv] : g[u])
			if(dist[v] > w + wv)
			{
				int tp = ((w / kv) + !!(w % kv)) * kv - w;
				dist[v] = w + wv + tp;
				pq.push({-dist[v], v});
				// printf("v[%d] -> v[%d] w: %d\n", u + 1, v + 1, dist[v]);
			}
	}
	return (dist[y] != INF ? dist[y] : -1);
}

int main()
{
    _;

	cin >> n >> m >> x >> y;
	x--, y--;
	
	g.resize(n);
	k.assign(n, INF);

	while (m--)
	{
		int a, b, ti, ki;	
		cin >> a >> b >> ti >> ki;
		a--, b--;
		g[a].push_back({b, ti, ki});
		g[b].push_back({a, ti, ki});
	}

	cout << dijkstra() << endl;
    
    return(0);
}
