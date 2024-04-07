#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int i, a, b, c;
    cin>>i;

    for (int j = 1; j <= i*2; j++)
    {
        a = (j + 1) / 2;
        b = a * a;
        c = a * a * a;
        if (j % 2 == 0)
        {
            b ++;
            c ++;
        }
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
}
