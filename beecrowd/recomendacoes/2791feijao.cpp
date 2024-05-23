#include <bits/stdc++.h>
using namespace std;

int main()
{
    int resposta = 0;
    for (int i = 0; i < 4; i++)
    {
        int c; cin >> c;
        if (c == 1) resposta = (i + 1);
    }
    cout << resposta << endl;
}
