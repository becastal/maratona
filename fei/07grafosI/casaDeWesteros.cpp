#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> grafo;
vector<bool> visitado;
vector<int> componentesConexos;
bool informanteInconsistente = false;
// quantos sao os componentes completamente conexos do grafo imputado?

void dfs(int v)
{
    visitado[v] = true;
    componentesConexos.back()++;

    for (auto u : grafo[v])
    {
        if (grafo[u] != grafo[v]) informanteInconsistente = true;
        if (!visitado[u]) dfs(u);
    }
}

int main()
{
    _;
    int n; cin >> n;
    grafo.resize(n);
    visitado.resize(n);
    bool teveD = false;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
    {
        char c; cin >> c;
        if (c == 'S')
        {
            grafo[i].push_back(j);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!visitado[i])
        {
            componentesConexos.push_back(0);
            dfs(i);
        }
    }
    
    sort(componentesConexos.begin(), componentesConexos.end(), greater<int>());
    if (informanteInconsistente) cout << -1 << endl;
    else
    {
        cout << componentesConexos.size() << endl;
        for (int i = 0; i < componentesConexos.size(); i++)
        {
            if (i != 0) cout << " ";
            cout << componentesConexos[i];
        }
        cout << endl;
    }

    return(0);
}
