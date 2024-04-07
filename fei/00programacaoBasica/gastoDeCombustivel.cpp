#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int tempoDeViagem, velocidadeMedia;
    
    cin>>tempoDeViagem;
    cin>>velocidadeMedia;
    
    int distanciaPercorrida;
    distanciaPercorrida = tempoDeViagem*velocidadeMedia;
    double litrosNecessarios;
    litrosNecessarios = distanciaPercorrida/12.0;
    
    cout<<fixed<<setprecision(3)<<litrosNecessarios<<endl;
}
