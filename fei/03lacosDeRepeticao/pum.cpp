#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int i, m;
    m = 1;
    cin>>i;
    string resposta;

    for (int j = 1; j <= i; j++)
    {
        int e = m + 2;
        for (m; m <= e; m++)
        {
            resposta += to_string(m) + " ";
        }
        cout<<resposta<<"PUM"<<endl;
        resposta = "";
        m++;
    }
}
