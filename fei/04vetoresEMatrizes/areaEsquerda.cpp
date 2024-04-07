#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    double Matriz[12][12];
    double resposta = 0.0;
    int quantidade = 0;
    string O;

    cin >> O;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            cin >> Matriz[i][j];
            if (i > j && i + j < 11)
            {
                resposta += Matriz[i][j];
                quantidade++;
            }
        }
    }

    if (O == "M")
    {
        resposta /= quantidade;
    }

    cout << fixed << setprecision(1) << resposta << endl;
    return 0;
}