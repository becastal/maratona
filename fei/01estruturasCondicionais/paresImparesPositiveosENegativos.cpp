#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int a, b, c, d, e;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    cin>>e;
    int quantidadePares = 0;
    int quantidadeImpares = 0;
    int quantidadePositivos = 0;
    int quantidadeNegativos = 0;

    if (a %2 == 0)
    {
        quantidadePares++;
    }
    else
    {
        quantidadeImpares++;
    }
    if (b %2 == 0)
    {
        quantidadePares++;
    }
    else
    {
        quantidadeImpares++;
    }
    if (c %2 == 0)
    {
        quantidadePares++;
    }
    else
    {
        quantidadeImpares++;
    }
    if (d %2 == 0)
    {
        quantidadePares++;
    }
    else
    {
        quantidadeImpares++;
    }
    if (e %2 == 0)
    {
        quantidadePares++;
    }
    else
    {
        quantidadeImpares++;
    }


    if (a > 0)
    {
        quantidadePositivos++;
    }
    else if (a != 0)
    {
        quantidadeNegativos++;
    }
    if (b > 0)
    {
        quantidadePositivos++;
    }
    else if (b != 0)
    {
        quantidadeNegativos++;
    }
    if (c > 0)
    {
        quantidadePositivos++;
    }
    else if (c != 0)
    {
        quantidadeNegativos++;
    }
    if (d > 0)
    {
        quantidadePositivos++;
    }
    else if (d != 0)
    {
        quantidadeNegativos++;
    }
    if (e > 0)
    {
        quantidadePositivos++;
    }
    else if (e != 0)
    {
        quantidadeNegativos++;
    }

    cout<<quantidadePares<<" valor(es) par(es)"<<endl;
    cout<<quantidadeImpares<<" valor(es) impar(es)"<<endl;
    cout<<quantidadePositivos<<" valor(es) positivo(s)"<<endl;
    cout<<quantidadeNegativos<<" valor(es) negativo(s)"<<endl;
}
