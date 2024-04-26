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

int N, C, S, B;

vector<int> dijkstra (int origem, vector<vector<pair<int, int>>>& grafo)
{
    vector<int> dist(N, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, origem });
    dist[origem] = 0;

    while (!pq.empty())
    {
        auto u = pq.top(); pq.pop();
        
        for (auto v : grafo[u.s])
        {
            if (dist[v.f] > dist[u.s] + v.s)
            {
                dist[v.f] = dist[u.s] + v.s;
                pq.push({ dist[v.f] , v.f });
            }
        }
    }
    return (dist);
}

int main()
{
    cin >> N >> C >> S >> B;
    vector<vector<pair<int, int>>> grafoBino (N);
    vector<vector<pair<int, int>>> grafoBandidos (N);

    for (int i = 0; i < C + S; i++)
    {
        int a, b, v; cin >> a >> b >> v; a--, b--;
        grafoBandidos[a].push_back({b, v}), grafoBandidos[b].push_back({a, v});
        if (i < C)
            grafoBino[a].push_back({b, v}), grafoBino[b].push_back({a, v});
    }

    vector<int> bandidos(B);
    for (int i = 0; i < B; i++)
        cin >> bandidos[i], bandidos[i]--;

    int K, F; cin >> K >> F; K--, F--;
    vector<int> distBino = dijkstra(F, grafoBino);
    vector<int> distBandidos = dijkstra(F, grafoBandidos);

    int tempoBino = distBino[K], resposta = 0;
    for (int i = 0; i < B; i++)
        if (distBandidos[bandidos[i]] <= tempoBino) resposta++;

    cout << resposta << endl;

    return 0;
}