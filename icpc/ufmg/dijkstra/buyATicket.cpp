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
typedef pair<ll, ll> ii;
typedef vector<vector<ii>> grafo;

grafo g;
vector<ll> t, dist;
int n, m;

void dijkstra()
{
	priority_queue<ii> pq;
	for (int i = 0; i < n; i++)
		pq.push({-dist[i], i});

	while (!pq.empty())
	{
		ll w = -pq.top().f;
		ll u = pq.top().s;
		pq.pop();

		if (dist[u] < w)
			continue;

		for (auto [v, vw] : g[u])
			if (dist[v] > dist[u] + vw)
			{
				dist[v] = dist[u] + vw;
				pq.push({-dist[v], v});
			}
	}
}

int main()
{
    _;

	cin >> n >> m;	
	g.resize(n);

	for (int i = 0; i < m; i++)
	{
		ll u, v, w; cin >> u >> v >> w; u--, v--;
		w *= 2;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	dist.resize(n);
	for (auto& i : dist)
		cin >> i;
	
	dijkstra();

	for (auto i : dist)
		cout << i << ' ';
	cout << endl;
    
    return(0);
}
