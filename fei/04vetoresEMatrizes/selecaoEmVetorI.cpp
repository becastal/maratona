#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    vector<double> a(100);

    for (int i = 0; i < 100; i++)
    {
        cin>>a[i];
        if (a[i] <= 10)
        {
            cout<<"A["<<i<<"] = "<<fixed<<setprecision(1)<<a[i]<<endl;
        }
    }

}
