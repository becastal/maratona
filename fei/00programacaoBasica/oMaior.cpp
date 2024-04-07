#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int a, b, c;
    cin>>a;
    cin>>b;
    cin>>c;

    int maiorAB;
    maiorAB = (a + b + abs(a - b))/2;

    int maiorXC;
    maiorXC = (maiorAB + c + abs(maiorAB - c))/2;
    cout<<maiorXC<<" eh o maior"<<endl;
}