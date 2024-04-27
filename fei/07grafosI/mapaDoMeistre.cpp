#include <iostream>
#include <map>
#include <vector>
#include <string>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

int main()
{
    _;
    int x, y; cin >> x >> y;
    map<char, pair<int, int>> movimentos{ {'>', {1, 0}}, {'<', {-1, 0}}, {'v', {0, 1}}, {'^', {0, -1}} };
    vector<bool> visitados(x * y, false);
    vector<string> mapa;
    for (int i = 0; i < y; i++)
    {
        string linha; cin >> linha;
        mapa.push_back(linha);
    }

    pair<int, int> posicao;
    pair<int, int> mov;
    bool possivel = true;
    while (true)
    {
        if (visitados[posicao.second*x + posicao.first]) { possivel = false; break; }
        visitados[posicao.second * x + posicao.first] = true;
        
        if (mapa[posicao.second][posicao.first] != '.') mov = movimentos[mapa[posicao.second][posicao.first]];
        posicao.first += mov.first;
        posicao.second += mov.second;

        
        if (posicao.second > (y - 1) || posicao.second < 0) { possivel = false; break; } // checando bounds superior e inferior
        if (posicao.first > (x - 1) || posicao.first < 0) { possivel = false; break; } // checando bounds laterais
        if (mapa[posicao.second][posicao.first] == '*') break;
    }
    if (possivel) cout << "*" << endl; else cout << "!" << endl;
}
