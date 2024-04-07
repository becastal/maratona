#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double a, b, notaFinal;
    cin>>a;
    cin>>b;


    notaFinal = (a*3.5 + b*7.5)/11;
    cout<<"MEDIA = "<<fixed<<setprecision(5)<<notaFinal<<endl;
    return 0;
}
