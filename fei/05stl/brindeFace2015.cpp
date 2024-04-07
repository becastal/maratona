#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#define dbg(x) cout << #x << " = " << x << endl;

using namespace std;

int main()
{
    int n; cin >> n;
    int brindes = 0;
    stack<string> palavras;


    for (int i = 0; i < n; i++)
    {
        if (palavras.size() == 0) palavras.push("FACE");
        string novaPalavra = "";
        for (int j = 0; j < 4; j++)
        {
            char letra; cin >> letra;
            novaPalavra += letra;
        }
        reverse(novaPalavra.begin(), novaPalavra.end());
        if (palavras.top() == novaPalavra)
        {
            palavras.pop();
            brindes++;
        }
        else
        {
            reverse(novaPalavra.begin(), novaPalavra.end());
            palavras.push(novaPalavra);
        }
    }

    cout << brindes << endl;

    return 0;
}
