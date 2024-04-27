#include <bits/stdc++.h>
#define dbg(x) cout << #x << " = " << x << endl
using namespace std;

vector<vector<int>> grafo;
vector<int> visitado;
vector<int> idade;
vector<int> indice;
int n, m, l;

int bfs(int origem)
{
    visitado.clear(); visitado.resize(n);
    queue<int> q;
    q.push(origem);
    visitado[origem] = true;

    int menorIdade = 101;
    while (!q.empty())
    {
        int v = q.front(); q.pop();
        for (auto u : grafo[v])
        {
            if (!visitado[u])
            {
                if (idade[u] < menorIdade) menorIdade = idade[u];
                q.push(u);
                visitado[u] = true;
            }
        }
    }
    return menorIdade;
    
}

int main()
{
    while (cin >> n >> m >> l)
    {
        for (int i = 0; i < n; i++)
        {
            int idd; cin >> idd;
            idade.push_back(idd);
            indice.push_back(i);
        }

        grafo.resize(n);
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y; x--, y--;
            grafo[y].push_back(x);
        }

        for (int i = 0; i < l; i++)
        {
            char instrucao; cin >> instrucao;
            if (instrucao == 'P')
            {
                int a; cin >> a; a--;
                a = indice[a];
                int chefeMaisNovo = bfs(a);
                if (chefeMaisNovo == 101) cout << "*" << endl;
                else cout << chefeMaisNovo << endl;
            }
            else
            {
                int a, b; cin >> a >> b; a--, b--;

                int tidd = idade[indice[a]];
                idade[indice[a]] = idade[indice[b]];
                idade[indice[b]] = tidd;

                int tidx = indice[a];
                indice[a] = indice[b];
                indice[b] = tidx;
            }
        }
        grafo.clear(); idade.clear(); indice.clear();
    }

    return(0);
}