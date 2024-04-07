#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n, g;
    while (cin >> n >> g)
    {
        vector<int> diferencasDeGols(n);
        for (int i = 0; i < n; i++)
        {
            int s, r;
            cin >> s >> r;
            diferencasDeGols[i] = (s - r);
        }

        sort(diferencasDeGols.begin(), diferencasDeGols.end(), greater<int>());
        int pontos = 0;
        for (int i = 0; i < n; i++)
        {
            while (diferencasDeGols[i] <= 0 && g > 0)
            {
                diferencasDeGols[i]++;
                g--;
            }
            if (diferencasDeGols[i] > 0) pontos += 3; else if (diferencasDeGols[i] == 0) pontos += 1;
        }
        cout << pontos << endl;
    }
    return 0;
}