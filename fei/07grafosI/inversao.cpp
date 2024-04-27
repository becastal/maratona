#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 1e5 + 10;
vector<vector<int>> grafo(MAX);
vector<int> distancia(MAX, -1);

vector<int> movimentos(int num)
{
    int posterior = (num + 1);
    int reverso = 0;
    int resto;
    while (num != 0)
    {
        resto = num % 10;
        reverso = reverso * 10 + resto;
        num /= 10;
    }
    vector<int> resposta;
    if (posterior <= MAX && distancia[posterior] == -1) resposta.push_back(posterior);
    if (reverso <= MAX && distancia[reverso] == -1) resposta.push_back(reverso);
    return(resposta);
}

int bfs(int o, int d)
{
    queue<int> q;
    q.push(o); distancia[o] = 0;

    while (!q.empty())
    {
        int v = q.front(); q.pop();
        if (v == d) return distancia[v];
        for (auto u : movimentos(v))
        {
            distancia[u] = distancia[v] + 1;
            q.push(u);
        }
    }
}

int main()
{
    _;
    int t; cin >> t;
    while (t--)
    {
        int origem, destino;
        cin >> origem >> destino;
        
        int minimoDeBotoes = bfs(origem, destino);
        cout << minimoDeBotoes << endl;
        
        grafo.clear(); distancia.clear();
        grafo.resize(MAX); distancia.resize(MAX, -1);
    }

    return(0);
}
