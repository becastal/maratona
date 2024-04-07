#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (true)
    {
        long long n, m;
        cin >> n >> m;
        if (n == -1 && m == -1) break;

        long long somador = 0;
        for (int i = 0; i < n; i++)
        {
            long c_i; cin >> c_i;
            somador += (n - i) * c_i;
        }
        long long total = somador * m;
        cout << (total)  << endl;
    }
}