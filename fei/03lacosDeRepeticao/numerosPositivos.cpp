#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    cin>>e;
    cin>>f;
    int quantidadePositivos = 0;

    if (a >= 0)
    {
        quantidadePositivos++;
    }
    if (b >= 0)
    {
        quantidadePositivos++;
    }
    if (c >= 0)
    {
        quantidadePositivos++;
    }
    if (d >= 0)
    {
        quantidadePositivos++;
    }
    if (e >= 0)
    {
        quantidadePositivos++;
    }
    if (f >= 0)
    {
        quantidadePositivos++;
    }
    cout<<quantidadePositivos<<" valores positivos"<<endl;
}
