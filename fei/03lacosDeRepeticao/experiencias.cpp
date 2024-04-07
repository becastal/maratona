#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double quantidadeCoelhos = 0, quantidadeRatos = 0, quantidadeSapos = 0;
    double total, i, q;
    string categoria;

    cin>>i;
    for (int j = 1; j <= i; j++)
    {
        cin>>q;
        total += q;

        cin>>categoria;
        if (categoria == "C")
        {
            quantidadeCoelhos += q;
        }
        else if (categoria == "R")
        {
            quantidadeRatos += q;
        }
        else
        {
            quantidadeSapos += q;
        }
    }
    cout<<"Total: "<<total<<" cobaias"<<endl;
    cout<<"Total de coelhos: "<<quantidadeCoelhos<<endl;
    cout<<"Total de ratos: "<<quantidadeRatos<<endl;
    cout<<"Total de sapos: "<<quantidadeSapos<<endl;
    cout<<"Percentual de coelhos: "<<fixed<<setprecision(2)<<(quantidadeCoelhos/total)*100<<" %"<<endl;
    cout<<"Percentual de ratos: "<<fixed<<setprecision(2)<<(quantidadeRatos/total)*100<<" %"<<endl;
    cout<<"Percentual de sapos: "<<fixed<<setprecision(2)<<(quantidadeSapos/total)*100<<" %"<<endl;
    return 0;
}
