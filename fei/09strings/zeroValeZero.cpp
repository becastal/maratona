#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main()
{
    while (true)
    {
        int m, n;
        cin >> m >> n;

        if (m == 0 && n == 0)
        {
            break;
        }

        int soma = m + n;
        string s = to_string(soma);

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '0')
            {
                cout << s[i];
            }
        }
        cout << endl;
    }
}
