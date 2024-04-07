#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int i;
    cin>>i;
    double ts = 0, tb = 0, ta = 0;
    double fs = 0, fb = 0, fa = 0;

    for (int j = 0; j < i; j++)
    {
        string nome;
        cin>>nome;

        double s, b, a;
        double s1, b1, a1;

        cin>>s>>b>>a;
        cin>>s1>>b1>>a1;

        ts += s;
        tb += b;
        ta += a;
        fs += s1;
        fb += b1;
        fa += a1;
    }
    cout<<"Pontos de Saque: "<<fixed<<setprecision(2)<<(fs/ts)*100<<" %."<<endl;
    cout<<"Pontos de Bloqueio: "<<fixed<<setprecision(2)<<(fb/tb)*100<<" %."<<endl;
    cout<<"Pontos de Ataque: "<<fixed<<setprecision(2)<<(fa/ta)*100<<" %."<<endl;
}
