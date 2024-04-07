#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string risada;
    cin >> risada;
    string vogais = "";

    for (int i = 0; i < risada.size(); i++)
    {
        if (risada[i] == 'a' || risada[i] == 'e' || risada[i] == 'i' || risada[i] == 'o' || risada[i] == 'u')
        {
            vogais += risada[i];
        }
    }

    int j = 0, k = vogais.size() - 1;
    bool ehPalindromo = true;
    while (j < k)
    {
        if (vogais[j] != vogais[k])
        {
            ehPalindromo = false;
            break;
        }
        j++;
        k--;
    }

    if (ehPalindromo)
    {
        cout << "S" << endl;
    }
    else
    {
        cout << "N" << endl;
    }
}
