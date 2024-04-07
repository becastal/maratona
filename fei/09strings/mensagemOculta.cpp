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

    for (int i = 0; i < n; i++)
    {
        string mensagem;
        getline(cin, mensagem);

        if (mensagem[0] != ' ')
        {
            cout << mensagem[0];
        }
        for (int j = 1; j < mensagem.size(); j++)
        {
            if (mensagem[j] != ' ' && mensagem[j - 1] == ' ')
            {
                cout << mensagem[j];
            }
        }
        cout << endl;
    }
    return 0;
}
