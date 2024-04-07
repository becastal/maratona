#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> gramas{300, 1500, 600, 1000, 150};
    int total = 0;
    for (int i = 0; i < 5; i++)
    {
        int q; cin >> q;
        total += q * gramas[i];
    }
    cout << total + 225 << endl;
}
