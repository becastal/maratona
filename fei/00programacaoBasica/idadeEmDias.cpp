#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int anos, meses, dias;
    
    cin>>dias;
    
    anos = dias / 365;
    dias -= anos * 365;
    
    meses = dias / 30;
    dias -= meses * 30;

    cout<<anos<<" ano(s)"<<endl;
    cout<<meses<<" mes(es)"<<endl;
    cout<<dias<<" dia(s)"<<endl;
}