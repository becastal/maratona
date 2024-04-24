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

int m;
map<string, vector<pair<string, string>>> grafo; // pair<vertice(idioma), aresta(palavra)>

int dijkstra(string origem, string destino)
{   
    priority_queue<pair<int, pair<char, string>>, vector<pair<int, pair<char, string>>>, greater<pair<int, pair<char, string>>>> pq;
    map<string, pair<int, char>> dist;
    for (auto p : grafo)
        dist.insert({p.f, {INF, '$'}});
    
    dist[origem] = {0, '$'};
    pq.push({0, {'$', origem}});

    while (!pq.empty())
    {
        pair<int, pair<char, string>> va = pq.top(); pq.pop();

        for (pair<string, string> vb : grafo[va.s.s])
        {
            if (dist[va.s.s].s == vb.s[0]) continue;
            int w = vb.s.size();

            if (dist[vb.f].f > dist[va.s.s].f + w)
            {
                dist[vb.f].f = dist[va.s.s].f + w;
                dist[vb.f].s = vb.s[0];
                pq.push({ dist[vb.f].f, { dist[vb.f].s, vb.f } });
                // cout << va.s.s << " enxerga " << vb.f << ", vindo com a inicial: " << dist[va.s.s].s << endl;
            }
        }
    }

    return dist[destino].f;
}

int main()
{
    while (cin >> m && m != 0)
    {
        string origem, destino; cin >> origem >> destino;
        for (int i = 0; i < m; i++)
        {
            string x, y, w; cin >> x >> y >> w;
            grafo[x].push_back({y, w});
            grafo[y].push_back({x, w});
        }

        int resp = dijkstra(origem, destino);
        cout << (resp == INF || resp == 0 ? "impossivel" : to_string(resp)) << endl;
    }

    return 0;
}