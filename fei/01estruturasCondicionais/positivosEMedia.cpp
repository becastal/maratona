#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double a, b, c, d, e, f;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    cin>>e;
    cin>>f;
    double quantidadePositivos = 0;
    double valorPositivos = 0;

    if (a > 0)
    {
        quantidadePositivos++;
        valorPositivos += a;

    }
    if (b > 0)
    {
        quantidadePositivos++;
        valorPositivos += b;
    }
    if (c > 0)
    {
        quantidadePositivos++;
        valorPositivos += c;
    }
    if (d > 0)
    {
        quantidadePositivos++;
        valorPositivos += d;
    }
    if (e > 0)
    {
        quantidadePositivos++;
        valorPositivos += e;
    }
    if (f > 0)
    {
        quantidadePositivos++;
        valorPositivos += f;
    }
    cout<<quantidadePositivos<<" valores positivos"<<endl;
    cout<<fixed<<setprecision(1)<<(valorPositivos / quantidadePositivos)<<endl;

}
