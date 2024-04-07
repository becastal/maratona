#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int i, j, soma = 0;
    cin>>i>>j;

    while (true)
    {
        if (j > 0)
        {
            break;
        }
        cin>>j;
    }

    for (int k = 0; k < j; k++)
    {
        soma += (i + k);
    }

    cout<<soma<<endl;

    return 0;
}
