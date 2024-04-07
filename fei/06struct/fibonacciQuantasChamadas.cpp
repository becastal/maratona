#include <bits/stdc++.h>
using namespace std;

int contador = 0;

int fibonacci(int n)
{
    contador++;
    if (n == 0) return 0;
    if (n == 1) return 1;
    return(fibonacci(n-1) + fibonacci(n-2));
}

int main()
{
    int t; cin >> t;
    for (int i = 0; i < t; i++)
    {
        int u; cin >> u;
        int f = fibonacci(u);
        cout << "fib(" << u << ") = " << contador - 1 << " calls = " << f << endl;
        contador = 0;
    }
}