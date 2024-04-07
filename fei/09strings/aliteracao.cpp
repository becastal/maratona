#include <iostream>
#include <vector>

using namespace std;
 
int main() {
    string frase;
    getline(cin, frase);
    while (frase != "")
    {
        vector<char> inicioPalavras;
        vector<int> contadorAliteracoes;
        int aliteracoes = 0;

        for (int i = 0; i < frase.size(); i++)
        {
            if (frase[i] >= 65 && frase[i] <= 90)
            {
                frase[i] += 32;
            }

            if (i == 0 || frase[i - 1] == ' ')
            {
                inicioPalavras.push_back(frase[i]);
                if (inicioPalavras.back() == inicioPalavras[inicioPalavras.size() - 2])
                {
                    contadorAliteracoes.back() += 1;
                }
                else
                {
                    contadorAliteracoes.push_back(0);
                }
            }
        }

        for (int j = 0; j < contadorAliteracoes.size(); j++)
        {
            if (contadorAliteracoes[j] > 0)
            {
                aliteracoes += 1;
            }
        }
        
        cout << aliteracoes << endl;
        getline(cin, frase);
    }
    return 0;
}