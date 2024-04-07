#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        string a, b;
        cin >> a >> b;
        int somador = 0;

        for (int j = 0; j < a.size(); j++)
        {
            if (b[j] < a[j])
            {
                somador += (b[j] - a[j]) + 26;
            }
            else
            {
                somador += b[j] - a[j];
            }
        }
        cout << somador << endl;
    }
    return 0;
}
