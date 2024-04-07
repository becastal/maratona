#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums(10);


    for (int i = 0; i < 10; i++)
    {
        int j;
        cin>>j;

        if (j <= 0)
        {
            nums[i] = 1;
        }
        else
        {
            nums[i] = j;
        }
        cout<<"X["<<i<<"] = "<<nums[i]<<endl;
    }
}
