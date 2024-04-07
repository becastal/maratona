#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    for (int i = 1; i <= 9; i += 2)
    {
        int j = i + 6;
        int m = j - 2;
        for (j; j >= m; j--)
        {
            cout<<"I="<<i<<" J="<<j<<endl;
        }
    }
}
