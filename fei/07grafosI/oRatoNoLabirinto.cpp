#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
const int INF = 0x3f3f3f3f;

map<string, vector<string>> grafo;
map<string, int> distancia;

int bfs(string origem, string saida)
{
    queue<string> q;
    q.push(origem); distancia[origem] = 0;
    for (auto const& a : distancia) distancia[a.first] = -1;

    while (!q.empty())
    {
        string v = q.front(); q.pop();
        if (v == saida) return(distancia[v]);
        for (auto u : grafo[v])
        {
            if (distancia[u] == -1)
            {
                distancia[u] = distancia[v] + 1;
                q.push(u);
            }
        }
    }
}

int main()
{
    _;
    int pontos, ligacoes;
    cin >> pontos >> ligacoes;

    for (int i = 0; i < ligacoes; i++)
    {
        string a, b;
        cin >> a >> b;

        grafo[a].push_back(b);
        grafo[b].push_back(a);
        distancia.insert({a, -1});
        distancia.insert({b, -1});
    }

    int distanciaPercorrida = bfs("Entrada", "*") + bfs("*", "Saida") + 2;
    cout << distanciaPercorrida << endl;
    
    return(0);
}
