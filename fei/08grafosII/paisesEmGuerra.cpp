#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <functional>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int n, e;

int dijkstra(int source, int destino, vector<int> d, vector<vector<pair<int, int>>>& g) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, source });
    d[source] = 0;

    while (!pq.empty()) {
        int vertice_saida = pq.top().s; pq.pop();
        if (vertice_saida == destino) return(d[vertice_saida]);

        for (auto& p : g[vertice_saida]) {
            int vertice_atual = p.f; \
                int weight = p.s;

            if (d[vertice_atual] > d[vertice_saida] + weight)
            {
                d[vertice_atual] = d[vertice_saida] + weight;
                pq.push({ d[vertice_atual], vertice_atual });
            }
        }
    }
    return INF;
}

int main()
{
    _;
    while (true)
    {
        cin >> n >> e;
        if (n == 0 && e == 0) break;

        vector<vector<pair<int, int>>> grafo(n);
        vector<int> distancias(n, INF);
        set<pair<int, int>> caminhos;
        for (int i = 0; i < e; i++)
        {
            int x, y, h; cin >> x >> y >> h; x--, y--;

            if (caminhos.count({ y, x }) == 0)
            {
                grafo[x].push_back({ y, h });
                caminhos.insert({ x, y });
            }
            else
            {
                grafo[x].push_back({ y, 0 });
                for (auto& c : grafo[y])
                    if (c.f == x)
                    {
                        c.s = 0;
                        break;
                    }
            }
        }

        int k; cin >> k;
        for (int i = 0; i < k; i++)
        {
            int o, d; cin >> o >> d; o--, d--;

            int dist = dijkstra(o, d, distancias, grafo);
            
            if (dist == INF) cout << "Nao e possivel entregar a carta" << endl;
            else cout << dist << endl;
        }
        cout << endl;
    }

    return(0);
}