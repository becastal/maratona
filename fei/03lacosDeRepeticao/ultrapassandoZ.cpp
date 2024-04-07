#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int i, j;
    cin>>i>>j;

    while (true)
    {
        if (j > i)
        {
            break;
        }
        cin>>j;
    }

    int k = i, somaInteiros = 0;
    while (somaInteiros < j)
    {
        somaInteiros += k;
        k++;
    }
    cout<<k-i<<endl;
}
