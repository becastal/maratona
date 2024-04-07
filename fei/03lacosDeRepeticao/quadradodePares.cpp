#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int i;
    cin>>i;

    if (i % 2 == 1)
    {
        i--;
    }

    for (int j = 2; j <= i; j+=2)
    {
        cout<<j<<"^2 = "<<j*j<<endl;
    }
    return 0;
}
