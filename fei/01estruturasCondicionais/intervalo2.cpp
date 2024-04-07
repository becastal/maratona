#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int i, k, l;
    cin>>i;

    k = 0;
    l = 0;
    for (int j = 0; j < i;j++)
    {
        cin>>k;
        if (k >= 10 && k <= 20) {
            l++;
        }
    }
    cout<<l<<" in"<<endl;
    cout<<i - l<<" out"<<endl;
}