#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#define dbg(x) cout << #x << " = " << x << endl;

using namespace std;

int main()
{
    string linha;
    bool primeira = true;

    while (getline(cin, linha))
    {
        vector<pair<int, int>> frequencia(129, {0, 0});
        for (int i = 0; i < linha.length(); i++)
        {
            frequencia[linha[i]].first++;
            frequencia[linha[i]].second = -(int)linha[i];
        }

        sort(frequencia.begin(), frequencia.end());

        if (primeira) {primeira = false;} else {cout << endl;}
        for (int i = 0; i < 129; i++)
        {
            if (frequencia[i].first > 0) cout << abs(frequencia[i].second) << " " << frequencia[i].first << endl;
        }
    }
}