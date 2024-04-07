#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    for (float i = 0; i < 2.1; i += 0.2)
    {
        for (float j = (1 + i); j < (3.1 + i); j++)
        {
            cout<<"I="<<i<<" J="<<j<<endl;
        }
    }
}
