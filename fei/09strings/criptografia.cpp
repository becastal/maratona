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
    cin.ignore();
    string mensagem;
    for (int i = 0; i < n; i++)
    {
        getline(cin, mensagem);

        for (int j = 0; j < mensagem.size(); j++)
        {
            bool letraEhMaiuscula = mensagem[j] >= 65 && mensagem[j] <= 90;
            bool letraEhMinuscula = mensagem[j] >= 97 && mensagem[j] <= 122;

            if (letraEhMaiuscula || letraEhMinuscula)
            {
                mensagem[j] += 3;
            }
        }

        int n = 0, m = mensagem.size() - 1;
        while (n < m)
        {
            char t;
            t = mensagem[n];
            mensagem[n] = mensagem[m];
            mensagem[m] = t;
            n++;
            m--;
        }

        for (int j = mensagem.size() / 2; j < mensagem.size(); j++)
        {
            mensagem[j] -= 1;
        }

        cout << mensagem << endl;
    }
}
