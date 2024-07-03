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
typedef vector<vector<pair<char, int>>> grafo;

// ainda tle. talvez um dijkstra pra cada letra do ascii antes e nao para cada letra da palavra.

vector<int> dijkstra(grafo& g, char ori)
{
	priority_queue<pair<int, char>> pq;
	pq.push({-0, ori});
	vector<int> dist(128, INF);
	dist[(int)ori] = 0;
	
	while (!pq.empty())
	{
		int w = -pq.top().f;
		char u = pq.top().s;
		pq.pop();
		if (dist[u] < w) continue;

		for (auto [v, vw] : g[u])
			if (dist[v] > w + vw)
			{
				dist[v] = w + vw;
				pq.push({-dist[v], v});
			}
	}

	return dist;
}

int main()
{
    _;

	string s, t; cin >> s >> t;
	int m; cin >> m;

	grafo g(128);
	while (m--)
	{
		char a, b; cin >> a >> b;
		int w; cin >> w;
		g[(int)a].push_back({b, w});
	}

	vector<vector<int>> dists(128, vector<int>(128));
	for (int i = 0; i < 128; i++)
		dists[i] = dijkstra(g, i);

	int res = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int di = dists[s[i]][t[i]]; 
		if (di == INF)
		{
			res = -1;
			break;
		}
		res += di;
	}

	cout << res << endl;
    
    return(0);
}
