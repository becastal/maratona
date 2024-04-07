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

vector<vector<pair<int, int>>> grafo;
vector<int> preco;
int n, m, c, k;

int dijkstra(int origem, int destino)
{
    preco = vector<int>(n, INF);
    priority_queue<pair<int, int>> q; q.push({-0, origem});

    while (!q.empty())
    {
        int v = q.top().second, d = -q.top().first;
        q.pop();
        if (d > preco[v]) continue;
        preco[v] = d;
        for (pair<int, int> u : grafo[v])
        {
            int w = d + u.first;
            if (preco[u.s] > w) q.push({w, u.s});
        }
    }
    return(preco[destino]);
}

int main() 
{ _;
    while (true)
    {
        cin >> n >> m >> c >> k;
        if (n == 0 && m == 0 && c == 0 && k ==0) break;

        grafo = vector<vector<pair<int, int>>>(n);
        for (int i = 0; i < m; i++)
        {
            int u, v, p;
            cin >> u >> v >> p;
            
            if ((u >= c && v >= c) || (u < c && v < c && abs(u - v) == 1))
            {
                grafo[u].push_back({v, p});
                grafo[u].push_back({v, p});
            }
            else if (u >= c && v < c) grafo[u].push_back({v, p});
            else if (v >= c && u < c) grafo[u].push_back({u, p});
        }

        cout << dijkstra(k, c - n) << endl;
    }
    return 0;
}
