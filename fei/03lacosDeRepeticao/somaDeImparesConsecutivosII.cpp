#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int i;
    cin>>i;

    for (int j = 0; j < i; j++)
    {
        int m, n, t;
        cin>>m>>n;

        if (m < n)
        {
            t = m;
            m = n;
            n = t;
        }

        int soma = 0;
        n++;
        for (n; n < m; n++)
        {
            if (n % 2 == 1)
            {
                soma += n;
            }
        }
        cout<<soma<<endl;
    }
}
