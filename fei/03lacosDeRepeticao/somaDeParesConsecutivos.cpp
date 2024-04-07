#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    while (true)
    {
        int i;
        cin>>i;

        if (i == 0)
        {
            break;
        }

        if (abs(i) % 2 == 1)
        {
            i++;
        }


        int somaParesConsecutivos = (i*5) + 20;
        cout<<somaParesConsecutivos<<endl;
    }
}
