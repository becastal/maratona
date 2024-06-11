#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    int m;
    cin >> n >> m;
    char nlogonia[n][m];
    for (int i = 0; i < n; i++)
    {
        string faixaMapa;
        cin >> faixaMapa;
        for (int j = 0; j < m; j++){
            nlogonia[i][j] = faixaMapa[j];
        }
    }

    int resposta = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            bool adjacenteEhMar = nlogonia[i-1][j] == '.' || nlogonia[i][j-1] == '.' || nlogonia[i+1][j] == '.' || nlogonia[i][j+1] == '.';
            bool bordaDaMatriz = i == 0 || j == 0 || i == n - 1 || j == m - 1;
            if (nlogonia[i][j] == '#' && (adjacenteEhMar || bordaDaMatriz))
            {
                resposta++;
            }
        }
    }
    cout << resposta << endl;
}
