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
        cin>>i;

        if (i == 0)
        {
            break;
        }

        int M[i][i];

        for (int j = 0; j < i; j++)
        {
            for (int k = 0; k < i; k++)
            {
                int menor, maior;
                int distanciaDaBorda;
                if (j < k)
                {
                    menor = j;
                    maior = k;
                }
                else
                {
                    menor = k;
                    maior = j;
                }

                if (k + j > i - 1)
                {
                    M[j][k] = i - maior;
                }
                else
                {
                    M[j][k] = menor + 1;
                }
                cout << setw(3) << M[j][k];
                if (k != i - 1)
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }


    return 0;
}
