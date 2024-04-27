#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

map<string, vector<string>> grafo;
map<string, bool> visitado;
map<string, int> distancia;
int n, G;

vector<string> bfs(string origem)
{
    queue<string> q;
    q.push(origem); 
    visitado[origem] = true;
    distancia[origem] = 0;

    vector<string> resposta;
    while (!q.empty())
    {
        string v = q.front(); q.pop();
        for (auto u : grafo[v])
        {
            if (!visitado[u])
            {
                q.push(u);
                visitado[u] = true;
                distancia[u] = distancia[v] + 1;
                if (distancia[u] <= G) resposta.push_back(u);
            }
        }
    }
    return(resposta);
}

int main()
{
    cin >> n >> G;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    vector<string> convidados = bfs("Rerisson");
    sort(convidados.begin(), convidados.end());

    cout << convidados.size() << endl;
    for (auto c : convidados) cout << c << endl;
    
    return(0);
}