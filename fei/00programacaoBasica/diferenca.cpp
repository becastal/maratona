#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double a, b, c, d, diferenca;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;

    diferenca = (a * b - c * d);
    cout<<"DIFERENCA = "<<diferenca<<endl;
    return 0;
}