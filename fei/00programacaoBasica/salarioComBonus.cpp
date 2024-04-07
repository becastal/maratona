#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    string nome;
    cin>>nome;

    double salarioBase;
    cin>>salarioBase;

    double vendas;
    cin>>vendas;

    double salarioComBonus;
    salarioComBonus = salarioBase + 0.15*vendas;

    cout<<"TOTAL = R$ "<<fixed<<setprecision(2)<<salarioComBonus<<endl;
    return 0;
}