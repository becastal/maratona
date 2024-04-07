#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    string senha;
    while (true)
    {
        cin>>senha;
        if (senha == "2002")
        {
            cout<<"Acesso Permitido"<<endl;
            break;
        }
        else
        {
            cout<<"Senha Invalida"<<endl;
        }
    }
}
