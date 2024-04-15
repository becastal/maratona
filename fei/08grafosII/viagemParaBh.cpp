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


int n, m;

void dijkstra(int source, vector<int>& d, vector<vector<pair<int, int>>>& g) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, source });
    d[source] = 0;

    while (!pq.empty()) {
        int vertice_saida = pq.top().s;
        pq.pop();

        for (auto& p : g[vertice_saida]) {
            int vertice_atual = p.f;\
            int weight = p.s;

            if (d[vertice_atual] > d[vertice_saida] + weight) 
            {
                d[vertice_atual] = d[vertice_saida] + weight;
                pq.push({ d[vertice_atual], vertice_atual });
            }
        }
    }
}

int main()
{
    _;
    while (cin >> n >> m)
    {
        vector<vector<pair<int, int>>> grafoA(n);
        vector<int> distanciasA(n, INF);
        vector<vector<pair<int, int>>> grafoO(n);
        vector<int> distanciasO(n, INF);

        for (int i = 0; i < m; i++)
        {
            int a, b, t, r;
            cin >> a >> b >> t >> r; a--, b--;

            t ? grafoA[a].push_back({ b, r }) : grafoO[a].push_back({ b, r });
        }

        dijkstra(0, distanciasA, grafoA);
        dijkstra(0, distanciasO, grafoO);
        pair<int, int> vias = { distanciasA[n - 1], distanciasO[n - 1] };
        cout << min(vias.f, vias.s) << endl;
    }

    return(0);
}