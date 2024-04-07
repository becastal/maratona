#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double pi =  3.14159;
    double raio;
    cin>>raio;

    double volume;
    volume = (4.0/3.0) * pi * (raio * raio * raio);
    cout<<"VOLUME = "<<fixed<<setprecision(3)<<volume<<endl;
}
