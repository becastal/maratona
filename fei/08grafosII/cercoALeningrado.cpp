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

int N, M, K;
double P;
vector<vector<int>> grafo;
vector<int> atiradores;

int dijkstra(int origem, int destino) {
    vector<int> d(N, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d[origem] = atiradores[origem];
    pq.push({ d[origem], origem });

    while (!pq.empty()) {
        int vs = pq.top().s; pq.pop();

        for (auto va : grafo[vs]) {

            if (d[va] > d[vs] + atiradores[va]) 
            {
                d[va] = d[vs] + atiradores[va];
                pq.push({ d[va], va });
            }
        }
    }
    return(d[destino]);
}

int main()
{
    _;
    while (cin >> N >> M >> K >> P)
    {
        grafo = vector<vector<int>> (N);
        atiradores = vector<int> (N, 0);

        for (int i = 0; i < M; i++)
        {
            int u, v; cin >> u >> v; u--, v--;
            grafo[u].push_back(v);
            grafo[v].push_back(u);
        }

        int A; cin >> A;
        for (int i = 0; i < A; i++)
        {
            int u; cin >> u; u--;
            atiradores[u]++;
        }

        int s, t; cin >> s >> t; s--, t--;
        int C = dijkstra(s, t);
        double ans = (K < C) ? 0.0 : pow(P, C);
        cout << fixed << setprecision(3) << ans << endl;
    }

    return(0);
}