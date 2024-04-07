#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t; cin >> t;
    int resposta = 0;
    for (int i = 0; i < 5; i++)
    {
        int n; cin >> n;
        if (n == t) resposta++;
    }
    cout << resposta << endl;
}