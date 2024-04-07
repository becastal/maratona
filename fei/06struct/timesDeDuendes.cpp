#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<pair<int, string>> duendes;
    for (int i = 0; i < n; i++)
    {
        string nome; cin >> nome;
        int idade; cin >> idade;
        duendes.push_back({-idade, nome});
    }
    sort(duendes.begin(), duendes.end());
    
    int quantTimes = n / 3;
    vector<vector<pair<int, string>>> times(quantTimes);
    for (int i = 0; i < n; i++)
    {
        times[i % quantTimes].push_back(duendes[i]);
    }

    for (int i = 0; i < quantTimes; i++)
    {
        cout << "Time " << (i + 1) << endl;
        for (auto duende : times[i])
        {
            cout << duende.second << " " << -duende.first << endl;
        }
        cout << endl;
    }

    return 0;
}