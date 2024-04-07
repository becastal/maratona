#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int maior = 0, indiceMaior = 0;
    int j;

    for (int i = 0; i <= 100; i++)
    {
        cin>>j;
        if (j > maior)
        {
            maior = j;
            indiceMaior = i + 1;
        }
    }
    cout<<maior<<endl;
    cout<<indiceMaior<<endl;
}
