#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;
    cin>>a>>b>>c;

    if ((a < b + c) && (b < a + c) && (c < b + a))
    {
        cout<<"Perimetro = "<<fixed<<setprecision(1)<<(a + b + c)<<endl;
    }
    else
    {
        cout<<"Area = "<<fixed<<setprecision(1)<<((a + b)*c)/2<<endl;
    }
}
