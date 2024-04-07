#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    //vector<int> n(999);
    int i;
    cin>>i;

    int j = 0;
    for (int k = 0; k < 1000; k++)
    {
        //n[k] = j;
        cout<<"N["<<k<<"] = "<<j<<endl;
        if (j == i - 1)
        {
            j = 0;
        }
        else
        {
            j++;
        }
    }

    return 0;
}
