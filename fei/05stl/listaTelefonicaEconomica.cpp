#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

#define dbg(x) cout << #x << " = " << x << endl;

using namespace std;

int main()
{
    int n;

    while (cin >> n)
    {
        vector<string> telefones(n);

        for (int i = 0; i < n; i++)
        {
            cin >> telefones[i];
        }
        sort(telefones.begin(), telefones.end());

        int caracteresEconomizados = 0;
        for (int i = 1; i < n; i++)
        {
            string temp = telefones[i];
            if (temp[0] == telefones[i - 1][0])
            {
                caracteresEconomizados++;
                temp[0] = '#';
                for (int j = 1; j < telefones[i].size(); j++)
                {
                    if (temp[j] == telefones[i - 1][j] && temp[j - 1] == '#')
                    {
                        caracteresEconomizados++;
                        temp[j] = '#';
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        cout << caracteresEconomizados << endl;
    }

    return 0;
}
