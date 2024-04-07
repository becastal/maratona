#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    vector<double> n(100);
    double i;
    cin>>i;

    n[0] = i;
    cout<<"N[0] = "<<fixed<<setprecision(4)<<i<<endl;
    for (int j = 1; j < 100; j++)
    {
        n[j] = n[j - 1] / 2.0;

        cout<<"N["<<j<<"] = "<<fixed<<setprecision(4)<<n[j]<<endl;
    }

    return 0;
}
