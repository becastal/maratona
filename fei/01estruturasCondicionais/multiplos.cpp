#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int a, b;
    cin>>a>>b;

    int temp;
    if (a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }

    if (a % b == 0)
    {
        cout<<"Sao Multiplos"<<endl;
    }
    else
    {
        cout<<"Nao sao Multiplos"<<endl;
    }
}
