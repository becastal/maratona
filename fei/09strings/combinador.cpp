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
        string primeiraString, segundaString;
        cin >> primeiraString >> segundaString;

        int j = 0, k =0;
        while (true)
        {
            if (j >= primeiraString.size() && j >= segundaString.size())
            {
                break;
            }

            if (j < primeiraString.size())
            {
                cout << primeiraString[j];
            }

            if (j < segundaString.size())
            {
                cout << segundaString[j];
            }

            j++;
        }
        cout << endl;
    }

}
