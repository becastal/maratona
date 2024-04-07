#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int i;
    cin>>i;
    
    for (int j = 1; j <= i; j++)
    {
        double a, b, c;
        cin>>a>>b>>c;
        cout<<fixed<<setprecision(1)<<((a*2)+(b*3)+(c*5))/10<<endl;
    }
}
