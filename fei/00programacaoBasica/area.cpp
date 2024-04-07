#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double pi =  3.14159;
    double a, b, c;
    cin>>a;
    cin>>b;
    cin>>c;

    double areaTriangulo;
    areaTriangulo = (a*c)/2;

    double areaCirculo;
    areaCirculo = pi*c*c;

    double areaTrapezio;
    areaTrapezio = ((a+b)*c)/2;

    double areaQuadrado;
    areaQuadrado = b*b;

    double areaRetangulo;
    areaRetangulo = a*b;

    cout<<"TRIANGULO: "<<fixed<<setprecision(3)<<areaTriangulo<<endl;
    cout<<"CIRCULO: "<<fixed<<setprecision(3)<<areaCirculo<<endl;
    cout<<"TRAPEZIO: "<<fixed<<setprecision(3)<<areaTrapezio<<endl;
    cout<<"QUADRADO: "<<fixed<<setprecision(3)<<areaQuadrado<<endl;
    cout<<"RETANGULO: "<<fixed<<setprecision(3)<<areaRetangulo<<endl;
}
