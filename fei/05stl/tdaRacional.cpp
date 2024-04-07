#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>

using namespace std;

int mdc(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return mdc(b, a % b);
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int n1, n2, d1, d2, nR, dR;
        string lixo;
        string operacao;

        cin >> n1 >> lixo >> d1 >> operacao >> n2 >> lixo >> d2;

        if (operacao == "+")
        {
            nR = ((n1*d2) + (n2*d1));
            dR = (d1*d2);
        }
        else if (operacao == "-")
        {
            nR = ((n1*d2) - (n2*d1));
            dR = (d1*d2);
        }
        else if (operacao == "*")
        {
            nR = (n1*n2);
            dR = (d1*d2);
        }
        else if (operacao == "/")
        {
            nR = (n1*d2);
            dR = (n2*d1);
        }

        int d = abs(mdc(nR, dR));
        cout << nR << "/" << dR << " = " << nR / d << "/" << dR / d << endl;
    }
}

