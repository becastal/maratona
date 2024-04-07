#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double a, b, c, notaFinal;
    cin>>a;
    cin>>b;
    cin>>c;


    notaFinal = (a*2 + b*3 + c*5)/10;
    cout<<"MEDIA = "<<fixed<<setprecision(1)<<notaFinal<<endl;
    return 0;
}
