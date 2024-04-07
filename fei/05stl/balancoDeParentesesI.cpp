#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    string expressao;
    while (cin >> expressao)
    {
        string parenteses = "";
        for (int i = 0; i < expressao.size(); i++)
        {
            if (expressao[i] == '(' || expressao[i] == ')')
            {
                parenteses += expressao[i];
            }
        }

        bool correto = true;
        if (parenteses.size() % 2 == 1)
        {
            correto = false;
        }
        else
        {
            int i = 0, j = parenteses.size() - 1;
            if (!(parenteses[i] == '(' && parenteses[j] == ')'))
            {
                correto = false;
            }
        }

        if (!correto) cout << "in";
        cout << "correct" << endl;
    }
}

