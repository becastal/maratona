#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    vector<int> a(20);

    for (int i = 0; i < 20; i++)
    {
        cin>>a[i];
    }

    int temp;
    for (int i = 0; i < 10; i++)
    {
        temp = a[i];
        a[i] = a[19-i];
        a[19-i] = temp;
    }

    for (int i = 0; i < 20; i++)
    {
        cout<<"N["<<i<<"] = "<<a[i]<<endl;
    }
}
