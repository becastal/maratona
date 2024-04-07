#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double salario;
    cin>>salario;

    double total;
    if (salario >= 0 && salario <= 2000)
    {
        cout<<"Isento"<<endl;
    }
    else if (salario > 2000 && salario <= 3000)
    {
        total = (salario-2000)*0.08;
        cout<<"R$ "<<fixed<<setprecision(2)<<total<<endl;
    }
    else if (salario > 3000 && salario <= 4500)
    {
        total = 80 + (salario-3000)*0.18;
        cout<<"R$ "<<fixed<<setprecision(2)<<total<<endl;
    }
    else if (salario > 4500)
    {
        total = 350 + (salario-4500)*0.28;
        cout<<"R$ "<<fixed<<setprecision(2)<<total<<endl;
    }
}
