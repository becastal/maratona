#include <bits/stdc++.h>
using namespace std;

int main()
{
    int abas, n;
    cin >> abas >> n;
    for (int i = 0; i < n; i ++)
    {
        string acao; cin >> acao;
        if (acao == "fechou") abas++;
        else abas--;
    }
    cout << abas << endl;
}
