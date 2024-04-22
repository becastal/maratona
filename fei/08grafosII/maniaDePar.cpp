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

// so adicionar uma aresta no grafo quando ja existir uma aresta anterior que acaba onde a aresta atual termina;
// ou seja, so se adicionaria uma aresta (b, c) se existir uma aresta (a, b) antes. e o peso dessa nova aresta (a, c) tem peso w(b, c) + w(a, b);
// depois, dijkstra normal nessa grafo gerado;

int c, v;

int dijkstra(int source, vector<vector<pair<int, int>>>& g) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> d(c, INF);
    pq.push({ 0, source });
    d[source] = 0;

    while (!pq.empty()) {
        int vs = pq.top().s; pq.pop();
        if (vs == c - 1) return d[vs];

        for (auto& p : g[vs]) {
            if (d[p.f] > d[vs] + p.s) 
            {
                d[p.f] = d[vs] + p.s;
                pq.push({ d[p.f], p.f });
            }
        }
    }
    return INF;
}

int main()
{
    cin >> c >> v;
    vector<vector<pair<int, int>>> grafo(c);
    vector<vector<pair<int, int>>> arestas(c);
    for (int i = 0; i < v; i ++)
    {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        arestas[v].push_back({u, w});
        arestas[u].push_back({v, w});
        if (arestas[u].size() > 0)
        {
            for (auto p : arestas[u]) // todos os jeitos de chegar em u com 1 aresta!
            {
                if (p.f == v) continue;
                grafo[p.f].push_back({v, w + p.s});
                grafo[v].push_back({p.f, w + p.s});
                // cout << p.f + 1 << " (" << u + 1 << ") " << v + 1 << " " << w + p.s << endl;
            }
        }
    }

    int r = dijkstra(0, grafo);
    cout << (r  == INF ? -1 : r) << endl;

    return(0);
}