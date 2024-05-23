#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, double> precos {{1001, 1.5}, {1002, 2.5}, {1003, 3.5}, {1004, 4.5}, {1005, 5.5}};
    int n; cin >> n;
    double total = 0.0;
    for (int i = 0; i < n; i++)
    {
        int id, quantidade;
        cin >> id >> quantidade;
        total += quantidade * precos[id];
    }
    cout << fixed << setprecision(2) << total << endl;
}
