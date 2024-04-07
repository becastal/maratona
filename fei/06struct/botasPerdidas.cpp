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
        vector<pair<int, int>> botas(31, {0, 0});
        for (int i = 0; i < n; i++)
        {
            int tamanho; cin >> tamanho;
            char pe; cin >> pe;

            if (pe == 'E')
            {
                botas[tamanho - 30].first++;
            }
            else
            {
                botas[tamanho - 30].second++;
            }
        }

        int totalDePares = 0;
        for (int i = 0; i < 31; i++)
        {
            totalDePares += min(botas[i].first, botas[i].second);
        }
        cout << totalDePares << endl;
    }
    
}