#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#define dbg(x) cout << #x << " = " << x << endl;

using namespace std;

int main()
{
    int t; cin >> t;

    for (int i = 0; i < t; i++)
    {
        int D, I, B;
        cin >> D >> I >> B;

        map<int, int> precoIngredientes;
        for (int j = 0; j < I; j++)
        {
            int preco; cin >> preco;
            precoIngredientes.insert({j, preco});
        }

        set<int> bolos;
        for (int j = 0; j < B; j++)
        {
            int quantIngredientes; cin >> quantIngredientes;
            int precoReceita = 0;
            for (int k = 0; k < quantIngredientes; k++)
            {
                int indiceIngrediente, numeroIngrediente;
                cin >> indiceIngrediente >> numeroIngrediente;
                precoReceita += precoIngredientes[indiceIngrediente] * numeroIngrediente;
            }
            bolos.insert(D / precoReceita);
        }
        int maxBolos = *bolos.rbegin();
        cout << maxBolos << endl;
    }

    return 0;
}
