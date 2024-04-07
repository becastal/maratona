#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    double Matriz[12][12];
    double resposta = 0.0;
    int coluna;
    string operacao;

    cin>>coluna;
    cin>>operacao;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            cin>>Matriz[i][j];
        }
    }

    for (int i = 0; i < 12; i++)
    {
        resposta += Matriz[i][coluna];
    }

    if (operacao == "M")
    {
        resposta /= 12;
    }

    cout<<fixed<<setprecision(1)<<resposta<<endl;
    return 0;
}


