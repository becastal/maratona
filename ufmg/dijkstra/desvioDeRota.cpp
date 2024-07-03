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
vector<int> d;
int n, m, c, k;

void dijkstra(int source, vector<int>& d, vector<vector<pair<int, int>>>& g) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, source });
    d[source] = 0;

    while (!pq.empty()) {
        int vs = pq.top().s;
        pq.pop();

        for (auto& p : g[vs]) {
            int va = p.f;
            int weight = p.s;

            if (d[va] > d[vs] + weight) 
            {
                d[va] = d[vs] + weight;
                pq.push({ d[va], va });
            }
        }
    }
}

int main() 
{ _;
    while (true)
    {
        cin >> n >> m >> c >> k;
        if (n == 0 && m == 0 && c == 0 && k == 0) break;

        grafo = vector<vector<pair<int, int>>>(n);
        d = vector<int>(n, INF);
        for (int i = 0; i < m; i++)
        {
            int u, v, p;
            cin >> u >> v >> p;
            
            if(u >= c && v >= c || u < c && v < c && abs(u-v)==1)
            {
                grafo[u].push_back({v, p});
                grafo[v].push_back({u, p});
            }
            if (u >= c && v < c) grafo[u].push_back({v, p});
            if (u < c && v >= c) grafo[v].push_back({u, p});
        }

        dijkstra(k, d, grafo);
        printf("%d\n", d[c-1]);
    }
    return 0;
}
