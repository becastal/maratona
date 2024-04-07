#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int a;
    cin >> a;

    for (int i = 0; i < a; i++)
    {
        int quantidadeVagoes;
        cin >> quantidadeVagoes;
        int vagoes[quantidadeVagoes];

        for (int k = 0; k < quantidadeVagoes; k++)
        {
            cin >> vagoes[k];
        }

        int resposta = 0;
        for (int k = 0; k < quantidadeVagoes; k++)
        {
            for (int l = k; l < quantidadeVagoes; l++)
            {
                if (vagoes[k] > vagoes[l])
                {
                    resposta++;
                }
            }
        }
        cout << "Optimal train swapping takes " << resposta << " swaps."<< endl;
    }


    return 0;
}
