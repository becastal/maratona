#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int i;
    cin>>i;
    
    for (int j = 1; j <= 10; j++)
    {
        cout<<j<<" x "<<i<<" = "<<i*j<<endl;
    }
}
