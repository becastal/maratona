#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (true)
    {
        int n, k;
        cin >> n >> k;
        if (n == 0 && k == 0) break;


        vector<pair<int, int>> carros; // <chegada, saida>
        for (int i = 0; i < n; i++)
        {
            int ci, si;
            cin >> ci >> si;
            carros.push_back({ci, si});
        }

        bool possivel = true;
        vector<pair<int, int>> estacionamento; // <chegada, saida>
        for (int i = 0; i < n; i++)
        {
            int ci = carros[i].first;
            int si = carros[i].second;

            for (int j = estacionamento.size() - 1; j >= 0; j--)
            {
                if (ci >= estacionamento[j].first && ci < estacionamento[j].second && si > estacionamento[j].second)
                {
                    possivel = false;
                    break;
                } 
            }
            if (!possivel) break;

            while (!estacionamento.empty() && estacionamento.back().second <= ci)
            {
                estacionamento.pop_back();
            }
            estacionamento.push_back({ci, si});

            if (estacionamento.size() > k) 
            {
                possivel = false;
                break;
            }
        }
        if (possivel) cout << "Sim" << endl; else cout << "Nao" << endl;
    }
    return 0;
}