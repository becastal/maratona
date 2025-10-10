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

int C, V;

int dijkstra(int source, int destino, vector<pair<int, int>>& dist, vector<vector<pair<int, int>>>& g) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    dist[source] = {0, INF};

    while (!pq.empty()) {
		int v = pq.top().s, d = pq.top().f; pq.pop();
		if(d > dist[v].f && d > dist[v].s) continue;

        for (auto u : g[v]) {
            // atualiza melhor impar
			if(dist[v].f + u.s < dist[u.f].s){
				dist[u.f].s = dist[v].f + u.s;
				pq.push({dist[u.f].s, u.f});
			}
            // atualiza melhor par
			if(dist[v].s + u.s < dist[u.f].f){
				dist[u.f].f = dist[v].s + u.s;
				pq.push({dist[u.f].f, u.f});
			}
        }
    }

    return( dist[destino].f == INF ? -1 : dist[destino].f );
}

int main()
{
    _;
    cin >> C >> V;
    vector<vector<pair<int, int>>> grafo(C);
    for (int i = 0; i < V; i ++)
    {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        grafo[v].push_back({u, w});
        grafo[u].push_back({v, w});
    }

    vector<pair<int, int>> dist(C, {INF, INF});
    cout << dijkstra(0, C-1, dist, grafo) << endl;

    return(0);
}
