#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#define dbg(x) cout << #x << " = " << x << endl;

using namespace std;

int main()
{
    while (true)
    {
        int m; cin >> m;
        if (m == 0) break;

        while (true)
        {
            queue<int> saida;
            int u; cin >> u;
            if (u == 0) break;
            saida.push(u);
            for (int i = 1; i < m; i++)
            {
                cin >> u;
                saida.push(u);
            }

            stack<int> entrada;
            for (int j = 1; j <= m; j++)
            {
                entrada.push(j);
                while (!saida.empty() && !entrada.empty() && saida.front() == entrada.top())
                {    
                    saida.pop();
                    entrada.pop();
                }                
            }
            if (saida.size() > 0) cout << "No" << endl; else cout << "Yes" << endl;
        }
        cout << endl;
    }
}