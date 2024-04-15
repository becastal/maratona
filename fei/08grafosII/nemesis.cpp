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

const vector<pair<int, int>> movimentos = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
int n, m;

int posicaoPeso(pair<int, int> pos, vector<vector<char>>& mapa)
{
    if (mapa[pos.f][pos.s] == '.' || mapa[pos.f][pos.s] == 'E') return 0;
    else return (mapa[pos.f][pos.s] - '0');
}

bool posicaoValida(pair<int, int> pos, vector<vector<char>>& mapa)
{
    return (pos.f >= 0 && pos.f < n && pos.s >= 0 && pos.s < m && mapa[pos.f][pos.s] != '#');
}

int dijkstra(pair<int, int> origem, pair<int, int> destino, vector<vector<int>> d, vector<vector<char>>& mapa) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({ 0, origem });
    d[origem.f][origem.s] = 0;

    while (!pq.empty()) {
        pair<int, int> vs = pq.top().s; pq.pop();
        if (vs == destino) return(d[vs.f][vs.s]);

        for (auto p : movimentos) {
            pair<int, int> va = { vs.f + p.f , vs.s + p.s };
            if (!posicaoValida(va, mapa)) continue;
            int peso = posicaoPeso(va, mapa);
            
            if (d[va.f][va.s] > d[vs.f][vs.s] + peso)
            {
                d[va.f][va.s] = d[vs.f][vs.s] + peso;
                pq.push({ d[va.f][va.s], va});
            }
        }
    }
    return(INF);
}

int main()
{
    _;
    cin >> n >> m;
    vector<vector<char>> mapa(n, vector<char>(m));
    vector<vector<int>> distancias(n, vector<int>(m, INF));
    pair<int, int> origem, destino;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        cin >> mapa[i][j];
        if (mapa[i][j] == 'H') origem = { i, j };
        else if (mapa[i][j] == 'E') destino = { i, j };
    }
    
    int energiaHerculea = dijkstra(origem, destino, distancias, mapa);

    if (energiaHerculea == INF) cout << "ARTSKJID" << endl;
    else cout << energiaHerculea << endl;

    return(0);
}