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

// dijkstra pra cada bandido, marcando a distancia de cada um deles pra cada vertice do grafo. 
// dijkstra do bino, que tenta chegar no destino mas considerando primeiro sempre os caminhos com menos bandidos.
int N, C, S, B;

void dijkstraBandidos(int indice, int origem, vector<vector<int>>& d, vector<vector<pair<int, int>>>& g)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, origem });
    d[origem][indice] = 0;

    while (!pq.empty()) {
        int vs = pq.top().s;
        pq.pop();

        for (auto& p : g[vs]) {
            int va = p.f;
            int weight = p.s;

            if (d[va][indice] > d[vs][indice] + weight) 
            {
                d[va][indice] = d[vs][indice] + weight;
                pq.push({ d[va][indice], va });
            }
        }
    }
}

int dijkstraBino(int origem, int destino, vector<vector<int>>& dBandidos, vector<vector<pair<int, int>>> g)
{
    // de algum jeito, esse dijkstra tem que priorizar antes os caminhos em que ele mata menos pessoas e percorre menor distancia;
    // tambem manter tracking dos bandidos que matou!
    //
    // FILA:
    // os dados sao: < quantidade de bandidos (nao matados!) que, chegando no novo vertice com o novo peso, ele vai encontrar,
    //                 peso do caminho,
    //                 indice da nova posicao >
    // 
    // usando vector ao inves de priority queue porque eu preciso alterar os valores dele diretamente e acho que daria rolo se tentasse com pq.
    //
    // DIST:
    // os dados sao: < peso ate a posicao, bandidos matados na posicao >


    vector<bool> matou(B, false);
    vector<pair<int, pair<int, int>>> fila;
    vector<pair<int, int>> distBino (N, {INF, 0});

    fila.push({0, {0, origem}});
    distBino[origem] = {0, 0};

    while (!fila.empty())
    {
        auto u = fila.front();  
    }
    return (INF);
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

    vector<vector<int>> distBandidos(N, vector<int>(B, INF));
    for (int i = 0; i < B; i++)
    {
        int posicao; cin >> posicao; posicao--;
        dijkstraBandidos(i, posicao, distBandidos, grafoBandidos);
    }

    int binoOrigem, binoDestino; cin >> binoOrigem >> binoDestino; binoOrigem--, binoDestino--;
    cout << dijkstraBino(origem, destino, distBandidos, grafoBino) << endl;
    return 0;
}
