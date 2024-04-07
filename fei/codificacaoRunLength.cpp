#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#define dbg(x) cout << #x << " = " << x << endl;

using namespace std;

int main()
{
    string linha;

    while (getline(cin, linha))
    {
        queue<pair<int, char>> fila;
        int contadorRepeticoes = 1;
        for (int i = 0; i < linha.size(); i++)
        {
            if (linha[i] == linha[i + 1] && contadorRepeticoes < 9)
            {
                contadorRepeticoes++;
            }
            else
            {
                fila.push({contadorRepeticoes, linha[i]});
                contadorRepeticoes = 1;
            }
        }

        while (!fila.empty())
        {
            if (fila.front().first == 1)
            {
                cout << "1";
                while (!fila.empty() && fila.front().first == 1)
                {
                    cout << fila.front().second;
                    if (fila.front().second == '1') cout << '1';
                    fila.pop();
                }
                cout << "1";
            }
            else
            {
                cout << fila.front().first << fila.front().second;
                fila.pop();
            }
        }
        cout << endl;
    }
}

