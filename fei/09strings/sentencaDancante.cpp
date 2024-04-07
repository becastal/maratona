#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string sentence;
    getline(cin, sentence);

    while (sentence != "")
    {
        int contadorCaracteres = 0;
        for (int i = 0; i < sentence.size(); i++)
        {
            bool letraEhMaiuscula = sentence[i] >= 65 && sentence[i] <= 90;
            bool letraEhMinuscula = sentence[i] >= 97 && sentence[i] <= 122;
            if (letraEhMaiuscula)
            {
                if (contadorCaracteres % 2 == 1)
                {
                    sentence[i] += 32;
                }
                contadorCaracteres++;
            }
            else if (letraEhMinuscula)
            {
                if (contadorCaracteres % 2 == 0)
                {
                    sentence[i] -= 32;
                }
                contadorCaracteres++;
            }
        }
        cout << sentence << endl;
        getline(cin, sentence);
    }
}
