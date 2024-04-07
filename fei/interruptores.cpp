// errei no detalhe. ver udebug.
#include <bits/stdc++.h>
using namespace std;

bool todasApagadas(vector<bool> v)
{
    for (auto i : v) if (i) return(false);
    return(true);
}

int main()
{
    int n, m; // quantidade de interruptores, quantidade de lampadas
    cin >> n >> m;
    vector<bool> lampadas(m, false);
    
    int l; cin >> l;
    for (int i = 0; i < l; i++)
    {
        int li; cin >> li; li--;
        lampadas[li] = true;
    }
    vector<bool> lampadasInicio = lampadas;

    vector<vector<int>> movimentos(n);
    for (int i = 0; i < n; i++)
    {
        int k; cin >> k;
        for (int j = 0; j < k; j++)
        {
            int ki; cin >> ki; ki--;
            movimentos[i].push_back(ki);
        }
    }

    int contador = 0;
    int i = 0;
    bool impossivel = false;
    while (!todasApagadas(lampadas))
    {
        for (auto j : movimentos[i])
            lampadas[j] = !lampadas[j];

        i++;
        if (i == movimentos.size())
        {
            if (lampadas == lampadasInicio) 
            {
                impossivel = true;
                break;
            }
            else 
            {
                i = 0;
                contador++;
            }
        }
    }
    if (impossivel) cout << -1 << endl; else cout << contador * n + i << endl;
}