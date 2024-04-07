#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    vector<long long int> fibonacci;
    fibonacci.push_back(0);
    fibonacci.push_back(1);

    for (int j = 2; j < 61; j++)
    {
        fibonacci.push_back(fibonacci[j - 1] + fibonacci[j - 2]);
    }

    int m;
    cin>>m;
    for (int n = 1; n <= m; n++)
    {
        int64_t i;
        cin>>i;

        cout<<"Fib("<<i<<") = "<<fibonacci[i]<<endl;
    }
}
