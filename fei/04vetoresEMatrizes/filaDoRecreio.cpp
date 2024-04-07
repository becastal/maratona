#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vector<int> filaNO; // nao ordenada
        vector<int> fila;

        for (int j = 0; j < m; j++)
        {
            int nota;
            cin >> nota;
            filaNO.push_back(nota);
            fila.push_back(nota);
        }
        sort(fila.begin(), fila.end(), greater<int>());

        int alunosSemMudanca = 0;
        for (int k = 0; k < fila.size(); k++)
        {
            if (filaNO.at(k) == fila.at(k))
            {
                alunosSemMudanca++;
            }
        }
        cout << alunosSemMudanca << endl;
    }

    return 0;
}
