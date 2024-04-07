#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int i, j, temp;
    cin>>i;
    cin>>j;


    if (i < j)
    {
        temp = i;
        i = j;
        j = temp;
    }

    int r = 0;
    for (int k = j + 1; k < i; k++)
    {
        if (abs(k) % 2 == 1)
        {
            r += k;
        }
    }
    cout<<r<<endl;
}
