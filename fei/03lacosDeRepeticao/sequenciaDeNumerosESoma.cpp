#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int i, j, temp, soma = 0;
    string resposta = "";

    while (true)
    {
        cin>>i;
        cin>>j;
        if (i <= 0 || j <= 0)
        {
            break;
        }
        if (i < j)
        {
            temp = i;
            i = j;
            j = temp;
        }
        for (j; j <= i; j++)
        {
            resposta += to_string(j) + " ";
            soma += j;
        }
        cout<<resposta<<"Sum="<<soma<<endl;
        resposta = "";
        soma = 0;
    }
}
