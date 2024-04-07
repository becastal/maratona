#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    while (true)
    {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)
        {
            break;
        }

        vector<string> linhas(m);
        for (int i = 0; i < n; i++)
        {
            cin >> linhas[i];
        }

        int a, b;
        cin >> a >> b;
        vector<string> novasLinhas(m);
        for (int i = 0; i < m; i++) // para cada linhas
        {
            for (int j = 0; j < linhas[i].size(); j++) // para cada caracter na linha
            {
                for (int k = 0; k < b / m; k++) // repetir caracter
                {
                    novasLinhas[i] += linhas[i][j];
                }
            }

            for (int l = 0; l < a / m; l++)
            {
                cout << novasLinhas[i] << endl;
            }
        }
        cout << endl;
    }
}

