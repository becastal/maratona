#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int main()
{

    int atributos;
    while (cin>>atributos)
    {
        int cartasM, cartasL;
        cin>>cartasM>>cartasL;

        int marcos[cartasM][atributos];
        for (int i = 0; i < cartasM; i++)
        {
            for (int j = 0; j < atributos; j++)
            {
                cin>>marcos[i][j];
            }
        }

        int leonardo[cartasL][atributos];
        for (int i = 0; i < cartasL; i++)
        {
            for (int j = 0; j < atributos; j++)
            {
                cin>>leonardo[i][j];
            }
        }

        int cartaEscolhidaM, cartaEscolhidaL;
        cin>>cartaEscolhidaM>>cartaEscolhidaL;
        int atributoEscolhido;
        cin>>atributoEscolhido;

        cartaEscolhidaM--; cartaEscolhidaL--; atributoEscolhido--;
        if (marcos[cartaEscolhidaM][atributoEscolhido] > leonardo[cartaEscolhidaL][atributoEscolhido])
        {
            cout<<"Marcos"<<endl;
        }
        else if (marcos[cartaEscolhidaM][atributoEscolhido] == leonardo[cartaEscolhidaL][atributoEscolhido])
        {
            cout<<"Empate"<<endl;
        }
        else
        {
            cout<<"Leonardo"<<endl;
        }
    }


    return 0;
}
