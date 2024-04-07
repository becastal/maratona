#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int i;
    cin>>i;
    
    for (int j = 1; j <= 10000; j++)
    {
        if (j % i == 2)
        {
            cout<<j<<endl;
        }
    }
}
