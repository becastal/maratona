#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int codigo, quantidade;
    cin>>codigo>>quantidade;
    double preco;

    if (codigo == 1)
    {
        preco = 4.0;
    }
    else if (codigo == 2)
    {
        preco = 4.5;
    }
    else if (codigo == 3)
    {
        preco = 5.0;
    }
    else if (codigo == 4)
    {
        preco = 2.0;
    }
    else if (codigo == 5)
    {
        preco = 1.5;
    }
    cout<<"Total: R$ "<<fixed<<setprecision(2)<<quantidade*preco<<endl;
    return 0;
}
