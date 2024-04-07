#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int i, x;
    cin>>i;

    if (i % 2 == 0)
    {
        i++;
    }

    x = (i + 10);
    for (i; i <= x; i+=2)
    {
        cout<<i<<endl;
    }
    return 0;
}
