#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int i, j;
    cin>>i>>j;

    string resposta = "";
    for (int m = 0; m < j; m += i)
    {
        for (int n = 1; n <= i; n++)
        {
            resposta += to_string(m + n) + " ";
        }
        cout<<resposta.substr(0, resposta.size()-1)<<endl;
        resposta = "";
    }
}
