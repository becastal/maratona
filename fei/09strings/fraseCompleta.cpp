#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        string frase;
        getline(cin, frase);
        vector<char> letrasNaFrase;

        for (int j = 0; j < frase.size(); j++)
        {
            if (frase[j] != ' ' && frase[j] != ',')
            {
                bool letraJaCadastrada = false;
                for (int k = 0; k < letrasNaFrase.size(); k++)
                {
                    if (frase[j] == letrasNaFrase[k])
                    {
                        letraJaCadastrada = true;
                        break;
                    }
                }
                if (!letraJaCadastrada)
                {
                    letrasNaFrase.push_back(frase[j]);
                }
            }
        }
        if (letrasNaFrase.size() == 26)
        {
            cout << "frase completa" << endl;
        }
        else if (letrasNaFrase.size() >= 13)
        {
            cout << "frase quase completa" << endl;
        }
        else
        {
            cout << "frase mal elaborada" << endl;
        }
    }
    return 0;
}
