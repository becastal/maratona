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

map<string, vector<pair<string, int>>> grafo;
map<string, int> dist;
int x, n, v;


int dijkstra() {
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    dist["varzea"] = 0;
    pq.push({ 0, "varzea" });

    while (!pq.empty()) {
        string vs = pq.top().s; pq.pop();
        if (vs == "alto") return(dist[vs]);

        for (auto& p : grafo[vs]) {
            string va = p.f;
            int weight = p.s;

            if (dist[va] > dist[vs] + weight)
            {
                dist[va] = dist[vs] + weight;
                pq.push({ dist[va], va });
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
        cin >> x >> n >> v;
        if (x == 0 && n == 0 && v == 0) break;
        // varzea -> alto
        for (int i = 0; i < n; i++)
        {
            string o, d;
            int t;
            cin >> o >> d >> t;
            grafo[o].push_back({ d, t });
            dist.insert({ o, INF });
            dist.insert({ d, INF });
        }

        int relogio = (x <= 30) ? 30 : 50;
        int trajeto = dijkstra();
        int total = relogio + trajeto;

        
        string resposta = (total > 60) ? "Ira se atrasar" : "Nao ira se atrasar";
        printf("%02d:%02d\n%s\n", (total / 60) + 17, (total % 60), resposta.c_str());

        grafo.clear();
        dist.clear();
    }

    return(0);
}