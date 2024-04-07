#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int total;
    cin>>total;
    int totalInicial;
    totalInicial = total;

    int notaDe100;
    notaDe100 = total / 100;
    total -= notaDe100*100;

    int notaDe50;
    notaDe50 = total / 50;
    total -= notaDe50*50;

    int notaDe20;
    notaDe20 = total / 20;
    total -= notaDe20*20;

    int notaDe10;
    notaDe10 = total / 10;
    total -= notaDe10*10;

    int notaDe5;
    notaDe5 = total / 5;
    total -= notaDe5*5;

    int notaDe2;
    notaDe2 = total / 2;
    total -= notaDe2*2;

    int notaDe1;
    notaDe1 = total / 1;
    total -= notaDe1*1;

    cout<<totalInicial<<endl;
    cout<<notaDe100<<" nota(s) de R$ 100,00"<<endl;
    cout<<notaDe50<<" nota(s) de R$ 50,00"<<endl;
    cout<<notaDe20<<" nota(s) de R$ 20,00"<<endl;
    cout<<notaDe10<<" nota(s) de R$ 10,00"<<endl;
    cout<<notaDe5<<" nota(s) de R$ 5,00"<<endl;
    cout<<notaDe2<<" nota(s) de R$ 2,00"<<endl;
    cout<<notaDe1<<" nota(s) de R$ 1,00"<<endl;
}
