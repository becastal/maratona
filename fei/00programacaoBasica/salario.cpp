#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int numero;
    cin>>numero;

    double horasTrabalhadas;
    cin>>horasTrabalhadas;

    double valorPorHora;
    cin>>valorPorHora;

    double salario;
    salario = horasTrabalhadas*valorPorHora;

    cout<<"NUMBER = "<<numero<<endl;
    cout<<"SALARY = U$ "<<fixed<<setprecision(2)<<salario<<endl;
    return 0;
}
