#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, saldo;
    cin >> n >> saldo;

    int menor = saldo;
    for (int i = 0; i < n; i++)
    {
        int j; cin >> j;
        saldo += j;
        if (saldo < menor) menor = saldo;
    }
    cout << menor << endl;
}
