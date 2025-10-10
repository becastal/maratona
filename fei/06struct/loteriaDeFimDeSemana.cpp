// sei la. nao to tao longe mas eh bem chato.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (true)
    {
        int n, c, k;
        cin >> n >> c >> k;
        if (n == 0 && c == 0 && k == 0) break;

        vector<pair<int, int>> contador(k, {0, 0}); // <quantas vezes repete, indice respectivo>
        for (int i = 0; i < k; i++) contador[i].second = i + 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int xi; cin >> xi;
                contador[xi-1].first++;
            }
        }
        sort(contador.begin(), contador.end());

        cout << contador[0].second;
        int i = 1;
        while (contador[i].first == contador[0].first)
        {
            cout << " " << contador[i].second;
            i++;
        }
        cout << endl;
    }
}
