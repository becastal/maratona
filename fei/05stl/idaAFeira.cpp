#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

#define dbg(x) cout << #x << " = " << x << endl;

using namespace std;

int main()
{
    int n; cin >> n;

    for (int i = 0; i < n; i++)
    {
        map<string, double> precos;
        int m; cin >> m;
        for (int j = 0; j < m; j++)
        {
            string fruta; cin >> fruta;
            double preco; cin >> preco;
            precos.insert({fruta, preco});
        }

        double total = 0;
        int p; cin >> p;
        for (int j = 0; j < p; j++)
        {
            string fruta; cin >> fruta;
            int quantidade; cin >> quantidade;
            total += precos[fruta] * quantidade;
        }
        cout << "R$ " << fixed << setprecision(2) << total << endl;
    }

    return 0;
}
