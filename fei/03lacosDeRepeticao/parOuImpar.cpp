#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int i;
    cin>>i;
    string resposta = "";

    for (int j = 1; j <= i; j++)
    {
        int m;
        cin>>m;

        if (m == 0)
        {
            resposta = "NULL";
        }
        else
        {
            if (abs(m) % 2 == 0) {
                resposta = "EVEN";
            }
            else
            {
                resposta = "ODD";
            }
            if (m > 0)
            {
                resposta += " POSITIVE";
            }
            else
            {
                resposta += " NEGATIVE";
            }
        }
        cout<<resposta<<endl;

    }
}
