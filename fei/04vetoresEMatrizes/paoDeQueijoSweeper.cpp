#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        int tabuleiro[n][m];
        int resposta[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> tabuleiro[i][j];
                resposta[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (tabuleiro[i][j] == 1)
                {
                    resposta[i][j] = 9;
                }
                else
                {
                    if (tabuleiro[i - 1][j] == 1 && i - 1 >= 0)
                    {
                        resposta[i][j] += 1;
                    }
                    if (tabuleiro[i][j - 1] == 1 && j - 1 >= 0)
                    {
                        resposta[i][j] += 1;
                    }
                    if (tabuleiro[i + 1][j] == 1 && i + 1 < n)
                    {
                        resposta[i][j] += 1;
                    }
                    if (tabuleiro[i][j + 1] == 1 && j + 1 < m)
                    {
                        resposta[i][j] += 1;
                    }
                }
                //cout << "i: " << i << ", j: " << j << " | resposta: " << resposta[i][j] << ", [i-1][j]: " << tabuleiro[i-1][j] << ", [i][j-1]: " << tabuleiro[i][j-1] << ", [i+1][j]: " << tabuleiro[i+1][j] << ", [i][j+1]: " << tabuleiro[i][j+1] << endl;
                cout << resposta[i][j];
            }
            cout << endl;
        }
    }
}
