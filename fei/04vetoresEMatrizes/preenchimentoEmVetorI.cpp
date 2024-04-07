#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums(10);
    int i;
    cin>>i;

    nums[0] = i;
    cout<<"N[0] = "<<i<<endl;
    for (int j = 1; j < 10; j++)
    {
        nums[j] = nums[j-1] * 2;
        cout<<"N["<<j<<"] = "<<nums[j]<<endl;
    }
}
