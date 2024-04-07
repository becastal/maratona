#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (true)
    {
        int p, s;
        cin >> p >> s;
        if (p == 0 && s == 0) break;        

        vector<pair<int, bool>> jogadores(p, {0, false}); // <posicao do jogador, pego em armadilha>
        vector<bool> armadilhas(s, false);
        for (int i = 0; i < 3; i++) 
        {
            int si; cin >> si;
            armadilhas[si] = true;
        }

        int n;
        cin >> n;
        queue<int> rolagens;
        for (int i = 0; i < n; i++)
        {
            int d1, d2;
            cin >> d1 >> d2;
            rolagens.push(d1 + d2);
        }

        int i = 0;
        int vencedor;
        while (!rolagens.empty())
        {
            if (!jogadores[i].second)
            {
                jogadores[i].first += rolagens.front(); rolagens.pop();
                if (jogadores[i].first > s) vencedor = i + 1;
                if (armadilhas[jogadores[i].first]) jogadores[i].second = true;
            }
            else
            {
                jogadores[i].second = false;
            }
            i++;
            if (i == p) i = 0;
        }
        cout << vencedor << endl;
    }
}