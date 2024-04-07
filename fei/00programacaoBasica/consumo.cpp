#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int distanciaPercorrida;
    cin>>distanciaPercorrida;

    double combustivelGasto;
    cin>>combustivelGasto;

    cout<<fixed<<setprecision(3)<<(distanciaPercorrida/combustivelGasto)<<" km/l"<<endl;
}
