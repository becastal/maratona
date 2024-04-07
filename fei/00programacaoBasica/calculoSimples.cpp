#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int codigo1, quantidade1;
    double valorUnitario1;
    cin>>codigo1>>quantidade1>>valorUnitario1;

    int codigo2, quantidade2;
    double valorUnitario2;
    cin>>codigo2>>quantidade2>>valorUnitario2;

    double totalItem1, totalItem2, totalPagar;
    totalItem1 = quantidade1*valorUnitario1;
    totalItem2 = quantidade2*valorUnitario2;
    totalPagar = totalItem1 + totalItem2;

    cout<<"VALOR A PAGAR: R$ "<<fixed<<setprecision(2)<<totalPagar<<endl;
}
