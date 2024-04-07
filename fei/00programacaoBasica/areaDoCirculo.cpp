#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double pi = 3.14159;
    double raio;
    cin>>raio;

    double area = pi*raio*raio;
    cout<<"A="<<fixed<<setprecision(4)<<area<<endl;
    return 0;
}
