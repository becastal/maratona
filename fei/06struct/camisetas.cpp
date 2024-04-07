// algum presentation error fdp que nao to afim de procurar agora. tirando isso tudo certo.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (true)
    {
        int n; cin >> n;
        if (n == 0) break;

        vector<pair<string, pair<char, string>>> camisetas;
        for (int i = 0; i < n; i++)
        {
            string nome, cor;
            char tamanho;
            cin.ignore(); getline(cin, nome);
            cin >> cor >> tamanho;
            camisetas.push_back(make_pair(cor, make_pair(abs(tamanho - 'P'), nome))); // matematica na hora de colocar o valor do tamanho no vetor pra ser mais facil de sortar tudo de uma vez so
        }
        sort(camisetas.begin(), camisetas.end());
        map<char, char> tradutor {{9, 'G'}, {3, 'M'}, {0, 'P'}}; // mapa pra limpar a matematica 
        for (auto c : camisetas)
        {
            cout << c.first << " " << tradutor[c.second.first] << " " << c.second.second << endl;
        }
        cout << endl;
    }
}
