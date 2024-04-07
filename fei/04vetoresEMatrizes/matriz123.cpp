#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int i;
    while (cin >> i)
    {
        int M[i][i];

        for (int j = 0; j < i; j++)
        {
            for (int k = 0; k < i; k++)
            {
                if (j + k == i - 1)
                {
                    M[j][k] = 2;
                }
                else if (j == k)
                {
                    M[j][k] = 1;
                }
                else
                {
                    M[j][k] = 3;
                }
                cout << M[j][k];
            }
            cout << endl;
        }
    }


    return 0;
}
