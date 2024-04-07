#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string palavra;
        cin >> palavra;

        if (palavra.size() > 3)
        {
            cout << 3 << endl;
        }
        else
        {
            if (palavra[1] == 'n' && palavra[2] == 'e' || palavra[0] == 'o' && palavra[1] == 'n' || palavra[0] == 'o' && palavra[2] == 'e')
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 2 << endl;
            }
        }

    }
    return 0;
}
