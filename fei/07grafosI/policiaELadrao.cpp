#include <iostream>
#include <vector>
#include <string>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

vector<vector<int>> grafo;
vector<bool> visitado;
int saida = 24;
bool policiaisVencem = false;

void dfs(int nodo)
{
    visitado[nodo] = true;
    if (nodo == saida) { policiaisVencem = true; return; }
    for (auto v : grafo[nodo])
    {
        if (!visitado[v]) dfs(v);
    }
}

string resposta;
int main()
{
    _;
    int t; cin >> t;
    while (t--)
    {
        grafo.resize(25);
        visitado.resize(25);
        vector<vector<bool>> mapa(5);
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                bool celula; cin >> celula;
                mapa[i].push_back(celula);
            }
        }

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (!mapa[i][j])
                {
                    if ((i - 1) >= 0 && !mapa[i - 1][j]) grafo[i * 5 + j].push_back((i - 1) * 5 + j);
                    if ((i + 1) < 5 && !mapa[i + 1][j]) grafo[i * 5 + j].push_back((i + 1) * 5 + j);
                    if ((j - 1) >= 0 && !mapa[i][j - 1]) grafo[i * 5 + j].push_back(i * 5 + (j - 1));
                    if ((j + 1) < 5 && !mapa[i][j + 1]) grafo[i * 5 + j].push_back(i * 5 + (j + 1));
                }
            }
        }

        dfs(0);

        if (policiaisVencem) cout << "COPS" << endl; else cout << "ROBBERS" << endl;
        grafo.clear(); visitado.clear(); policiaisVencem = false;
    }
}
