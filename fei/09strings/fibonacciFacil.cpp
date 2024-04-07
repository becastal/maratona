#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int fib[46];

    fib[0] = 0;
    fib[1] = 1;
    for (int i = 0; i < n; i++)
    {
        if (i - 2 >= 0)
        {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        cout << fib[i];
        if (i != n - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
}
