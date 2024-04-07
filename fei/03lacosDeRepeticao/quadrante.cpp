#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int x, y;
    string quadrante;
    while (true)
    {
        cin>>x>>y;
        if (x == 0 || y == 0)
        {
            break;
        }
        else
        {
            if (x > 0)
            {
                if (y > 0)
                {
                    quadrante = "primeiro";
                }
                else
                {
                    quadrante = "quarto";
                }
            }
            else
            {
                if (y > 0)
                {
                    quadrante = "segundo";
                }
                else
                {
                    quadrante = "terceiro";
                }
            }
            cout<<quadrante<<endl;
        }
    }
}
