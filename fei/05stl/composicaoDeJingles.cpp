#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

#define dbg(x) cout << #x << " = " << x << endl;

using namespace std;

int main()
{
    string composicao; cin >> composicao;
    map<char, int> notas;
    notas.insert({'W', 64});
    notas.insert({'H', 32});
    notas.insert({'Q', 16});
    notas.insert({'E',  8});
    notas.insert({'S',  4});
    notas.insert({'T',  2});
    notas.insert({'X',  1});

    while (composicao != "*")
    {
        int somador = 0;
        int compassosCorretos = 0;
        for (int i = 0; i < composicao.size(); i++)
        {
            if (composicao[i] == '/')
            {
                if (somador == 64) compassosCorretos++;
                somador = 0;
            }
            else
            {
                somador += notas[composicao[i]];
            }
        }
        cout << compassosCorretos << endl;
        cin >> composicao;
    }

    return 0;
}
