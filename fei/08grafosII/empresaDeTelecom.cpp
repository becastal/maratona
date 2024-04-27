#include <bits/stdc++.h>
#include <limits>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double dINF = std::numeric_limits<double>::infinity();
using namespace std;

int n;

struct antena
{
    double raio;
    int x;
    int y;
};

double distEntrePontos(pair<int, int> a, pair<int, int> b)
{
    return sqrt((a.f - b.f)*(a.f - b.f) + (a.s - b.s)*(a.s - b.s));
}

double dijkstra(int origem, int destino, vector<vector<pair<double, int>>>& g)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({-0, origem});
    vector<double> d(g.size(), dINF);
    d[origem] = 0;

    while (!pq.empty())
    {
        int vs = pq.top().s; pq.pop();
        if (vs == destino) return d[vs];

        for (auto& p : g[vs])
        {
            int va = p.s;
            double w = p.f;

            if (d[va] > d[vs] + w)
            {
                d[va] = d[vs] + w;
                pq.push({ d[va], va });
            }
        }
    }
    return(-1);
}

int main()
{
    _;
    while (true)
    {
        cin >> n;
        if (n == 0) break;

        vector<antena> antenas(n);
        for (int i = 0; i < n; i++)
            cin >> antenas[i].x >> antenas[i].y >> antenas[i].raio;

        vector<vector<pair<double, int>>> grafo(n);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                antena a1 = antenas[i], a2 = antenas[j];
                double dist = distEntrePontos({a1.x, a1.y}, {a2.x, a2.y});
                if (a1.raio >= dist)
                    grafo[i].push_back({dist, j});

                if (a2.raio >= dist) 
                    grafo[j].push_back({dist, i});
            }

        int C; cin >> C;
        while (C--)
        {
            int a1, a2; cin >> a1 >> a2; a1--, a2--;
            cout << floor(dijkstra(a1, a2, grafo)) << endl;
        }
    }

    return(0);
}