#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double salario;
    cin>>salario;

    double percentual;
    if (salario >= 0 && salario <= 400)
    {
        percentual = 0.15;
    }
    else if (salario > 400 && salario <= 800)
    {
        percentual = 0.12;
    }
    else if (salario > 800 && salario <= 1200)
    {
        percentual = 0.10;
    }
    else if (salario > 1200 && salario <= 2000)
    {
        percentual = 0.07;
    }
    else if (salario > 2000)
    {
        percentual = 0.04;
    }

    double novoSalario = salario*(1 + percentual);
    cout<<"Novo salario: "<<fixed<<setprecision(2)<<novoSalario<<endl;
    cout<<"Reajuste ganho: "<<fixed<<setprecision(2)<<novoSalario - salario<<endl;
    cout<<"Em percentual: "<<fixed<<setprecision(0)<<percentual*100<<" %"<<endl;
}
