#include <iostream> 
#include <vector>   
#include <map>      
#include <algorithm>
#include <utility>  

using namespace std;

int indiceMaoBatida(vector<vector<int>> maos, vector<pair<bool, bool>> coringa)
{
    for (int i = 0; i < maos.size(); i++)
    {
        if (maos[i].size() == 4 && !coringa[i].first)
        {
            bool batida = true;
            for (int j = 1; j < maos[i].size(); j++)
            {
                if (maos[i][j - 1] != maos[i][j])
                {
                    batida = false;
                    break;
                }
            }
            if (batida) return(i);
        }
    }
    return(-1);
}


int cartaDescartavel(vector<int> mao)
{
    vector<pair<int, int>> cartas; // <repeticoes da carta, valor da carta> 

    cartas.push_back({ 1, mao[0] });
    for (int i = 1; i < mao.size(); i++)
    {
        if (mao[i] == mao[i - 1]) cartas.back().first++;
        else cartas.push_back({ 1, mao[i] });
    }
    sort(cartas.begin(), cartas.end());
    for (int i = 0; i < mao.size(); i++) if (mao[i] == cartas[0].second) return(i);
    return(-1);
}


int main()
{
    int n, k;
    cin >> n >> k; k--;
    map<char, int> valores{ {'A', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'D', 10}, {'Q', 11}, {'J', 12}, {'K', 13}};
    map<int, int> proximo;
    vector<pair<bool, bool>> coringa(n, { false, false }); // <tem o coringa, primeira rodada com o coringa>
    coringa[k] = { true, true };

    vector<vector<int>> maos(n);
    for (int i = 0; i < n; i++)
    {
        string mao; cin >> mao;
        for (int j = 0; j < 4; j++)
        {
            maos[i].push_back(valores[mao[j]]);
        }
        sort(maos[i].begin(), maos[i].end());
        if (i != n - 1) proximo.insert({ i, i + 1 }); else proximo.insert({ i, 0 });
    }

    int maoBatida;
    while (true)
    {
        int indiceDescarte = (cartaDescartavel(maos[k]));
        if (coringa[k].first && coringa[k].second)
        {
            coringa[k].second = false;
            maos[proximo[k]].push_back(maos[k][indiceDescarte]);
            maos[k].erase(maos[k].begin() + indiceDescarte);
        }
        else if (coringa[k].first && !coringa[k].second)
        {
            coringa[k].first = false;
            coringa[proximo[k]] = { true, true };
        }
        else
        {
            maos[proximo[k]].push_back(maos[k][indiceDescarte]);
            maos[k].erase(maos[k].begin() + indiceDescarte);
        }
        sort(maos[proximo[k]].begin(), maos[proximo[k]].end());

        k = proximo[k];
        maoBatida = indiceMaoBatida(maos, coringa);
        if (maoBatida != -1) break;
    }
    cout << (maoBatida + 1) << endl;
}
