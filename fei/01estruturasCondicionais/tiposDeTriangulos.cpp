#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;
    double aS, bS, cS;
    cin>>a>>b>>c;

    if (a > b && a > c)
    {
        aS = a;
        if (b > c)
        {
            bS = b;
            cS = c;
        }
        else
        {
            bS = c;
            cS = b;
        }
    }
    else if (b > a && b > c)
    {
        aS = b;
        if (a > c)
        {
            bS = a;
            cS = c;
        }
        else
        {
            bS = c;
            cS = a;
        }
    }
    else
    {
        aS = c;
        if (a > b)
        {
            bS = a;
            cS = b;
        }
        else
        {
            bS = b;
            cS = a;
        }
    }

    if ((aS < bS + cS) && (bS < aS + cS) && (cS < aS + bS))
    {
        if (aS*aS == bS*bS + cS*cS)
        {
            cout<<"TRIANGULO RETANGULO"<<endl;
        }
        else if (aS*aS > bS*bS + cS*cS)
        {
            cout<<"TRIANGULO OBTUSANGULO"<<endl;
        }
        else if (aS*aS < bS*bS + cS*cS)
        {
            cout<<"TRIANGULO ACUTANGULO"<<endl;
        }
        if (aS == bS && bS == cS)
        {
            cout<<"TRIANGULO EQUILATERO"<<endl;
        }
        else if (aS == bS || bS == cS)
        {
            cout<<"TRIANGULO ISOSCELES"<<endl;
        }
    }
    else
    {
        cout<<"NAO FORMA TRIANGULO"<<endl;
    }
}
