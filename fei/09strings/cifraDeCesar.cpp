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
        string decodificado;
        cin >> decodificado;
        int offset;
        cin >> offset;

        for (int j = 0; j < decodificado.size(); j++)
        {
            if (decodificado[j] - offset < 65)
            {
                decodificado[j] += 26;
            }
            decodificado[j] -= offset;
        }
        cout << decodificado << endl;
    }

}
