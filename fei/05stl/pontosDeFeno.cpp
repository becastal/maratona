#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

#define dbg(x) cout << #x << " = " << x << endl;

using namespace std;

int main()
{
    map<string, long long> pontos;
    int m, n;
    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        string chave; cin >> chave;
        long long valor; cin >> valor;
        pontos.insert({chave, valor});
    }

    for (int i = 0; i < n; i++)
    {
        string palavra;
        long long salario = 0;
        while (palavra != ".")
        {
            cin >> palavra;
            salario += pontos[palavra];
        }
        cout << salario << endl;
    }

    return 0;
}
