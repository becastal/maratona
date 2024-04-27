#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> grafo;
vector<bool> visitado;
bool temCiclo = false;
int origem;

void dfs(int v)
{
    visitado[v] = true;

    for (auto u : grafo[v])
    {
        if (u == origem) temCiclo = true;
        else if (!visitado[u]) dfs(u);
    }
}

int main()
{
    _;
    int t;
    cin >> t;

    string resposta = "";
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        grafo.resize(n); visitado.resize(n);

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b; a--, b--;
            grafo[b].push_back(a);
        }

        for (int i = 0; i < n; i++)
        {
            visitado.clear(); visitado.resize(n);
            origem = i;
            dfs(i);
            if (temCiclo) break;
        }
        // if (temCiclo) cout << "SIM" << endl; else cout << "NAO" << endl;
        if (temCiclo) resposta += "SIM\n"; else resposta += "NAO\n";

        grafo.clear(); visitado.clear();
        temCiclo = false;
    }
    cout << resposta;

    return(0);
}