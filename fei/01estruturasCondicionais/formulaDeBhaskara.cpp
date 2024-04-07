#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;
    cin>>a>>b>>c;

    double delta;
    delta = (b*b) - (4*a*c);

    if (delta < 0 || a == 0)
    {
        cout<<"Impossivel calcular"<<endl;
    }
    else
    {
        double raiz1, raiz2;
        raiz1 = (- b + sqrt(delta))/(2*a);
        raiz2 = (- b - sqrt(delta))/(2*a);

        cout<<"R1 = "<<fixed<<setprecision(5)<<raiz1<<endl;
        cout<<"R2 = "<<fixed<<setprecision(5)<<raiz2<<endl;
    }
}
