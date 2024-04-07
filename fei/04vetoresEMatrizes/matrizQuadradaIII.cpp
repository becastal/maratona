#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    while (true)
    {
        int i;
        cin >> i;

        if (i == 0)
        {
            break;
        }

        int matriz[i][i];
        int maiorNum = pow(2, (2 * (i - 1))); // nao da pra usar a funcao pow dentro de to_string direto porque ela retorna um float e isso atrapalha na hora de contar caracteres
        int maxEspacos = to_string(maiorNum).length();
        for (int j = 0; j < i; j++)
        {
            for (int k = 0; k < i; k++)
            {
                matriz[j][k] = pow(2, (j + k));
                cout << setw(maxEspacos) << matriz[j][k];
                if (k != i - 1)
                {
                    cout<<" ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }

    return 0;
}
