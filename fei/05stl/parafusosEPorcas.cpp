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
        vector<int> parafusos;
        vector<int>::iterator itr;
        for (int i = 0; i < n; i++)
        {

            int x, y; cin >> x >> y;
            for (int j = x; j <= y; j++)
            {
                parafusos.push_back(j);
            }

        }
        int num; cin >> num;
        sort(parafusos.begin(), parafusos.end());
        int from = find(parafusos.begin(), parafusos.end(), num) - parafusos.begin();
        reverse(parafusos.begin(), parafusos.end());
        int to = parafusos.size() - 1 - (find(parafusos.begin(), parafusos.end(), num) - parafusos.begin());

        if (to != -1)
        {
            cout << num << " found from " << from << " to " << to << endl;
        }
        else
        {
            cout << num << " not found" << endl;
        }
    }

    return 0;
}
