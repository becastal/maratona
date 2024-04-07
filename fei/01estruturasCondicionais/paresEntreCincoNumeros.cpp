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
    int quantidadePares = 0;

    if (a %2 == 0)
    {
        quantidadePares++;
    }
    if (b %2 == 0)
    {
        quantidadePares++;
    }
    if (c %2 == 0)
    {
        quantidadePares++;
    }
    if (d %2 == 0)
    {
        quantidadePares++;
    }
    if (e %2 == 0)
    {
        quantidadePares++;
    }
    if (f %2 == 0)
    {
        quantidadePares++;
    }
    cout<<quantidadePares<<" valores pares"<<endl;
}
