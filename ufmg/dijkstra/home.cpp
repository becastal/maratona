#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 1999999998;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;
typedef pair<int, int> ii;
typedef map<ii, vector<pair<ii, int>>> grafo;

int n, m;
ii pa, pb; 
grafo g;

bool cmpy (ii a, ii b)
{
	return (a.s != b.s ? a.s < b.s : a.f < b.f);
}

int dijkstra ()
{
	priority_queue<pair<int, ii>> pq;
	map<ii, int> dist;
	for (auto [pi, v] : g)
		dist[pi] = INF;
	dist[pa] = 0;
	pq.push({-0, pa});

	while (!pq.empty())
	{
		int w = -pq.top().f;
		ii u = pq.top().s;
		pq.pop();
		if (dist[u] < w)
			continue;

		dist[u] = w;
		for (auto [v, vw] : g[u])
			if (dist[v] > w + vw)	
			{
				dist[v] = w + vw;
				pq.push({-dist[v], v});
			}
	}

	return dist[pb];
}

int main()
{
    _;

	cin >> n >> m;
	cin >> pa.f >> pa.s >> pb.f >> pb.s;

	vector<ii> p(m);
	for (auto& pi : p)
		cin >> pi.f >> pi.s;

	g[pa].push_back({pb, abs(pa.f - pb.f) + abs(pa.s - pb.s)});
	g[pb].push_back({pa, abs(pa.f - pb.f) + abs(pa.s - pb.s)});
	for (auto pi : p)
	{
		g[pa].push_back({pi, min(abs(pa.f - pi.f), abs(pa.s - pi.s))});
		g[pi].push_back({pa, abs(pa.f - pi.f) + abs(pa.s - pi.s)});

		g[pb].push_back({pi, min(abs(pb.f - pi.f), abs(pb.s - pi.s))});
		g[pi].push_back({pb, abs(pb.f - pi.f) + abs(pb.s - pi.s)});
	}

	sort(p.begin(), p.end());
	for (int i = 0; i < m - 1; i++)
	{
		int d = min(abs(p[i].f - p[i + 1].f), abs(p[i].s - p[i + 1].s));
		g[p[i]].push_back({p[i + 1], d});
		g[p[i + 1]].push_back({p[i], d});
	}

	sort(p.begin(), p.end(), cmpy);
	for (int i = 0; i < m - 1; i++)
	{
		int d = min(abs(p[i].f - p[i + 1].f), abs(p[i].s - p[i + 1].s));
		g[p[i]].push_back({p[i + 1], d});
		g[p[i + 1]].push_back({p[i], d});
	}

	cout << dijkstra() << endl;
    
    return(0);
}

