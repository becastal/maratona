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

    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;

        bool encaixa = true;
        for (int j = 0; j < b.size(); j++)
        {
            if (a[a.size() - 1 - j] != b[b.size() - 1 - j])
            {
                encaixa = false;
                break;
            }
        }

        if (!encaixa)
        {
            cout << "nao ";
        }
        cout << "encaixa" << endl;
    }

}
