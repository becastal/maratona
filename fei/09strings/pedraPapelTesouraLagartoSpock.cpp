#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int c;
    cin >> c;

    for (int i = 0; i < c; i++)
    {
        string r, s;
        cin >> r >> s;

        if (r == s)
        {
            cout << "empate" << endl;
        }
        else if (r == "tesoura")
        {
            if (s == "papel" || s == "lagarto")
            {
                cout << "rajesh" << endl;
            }
            else if (s == "pedra" || s == "spock")
            {
                cout << "sheldon" << endl;
            }
        }
        else if (r == "papel")
        {
            if (s == "pedra" || s == "spock")
            {
                cout << "rajesh" << endl;
            }
            else if (s == "tesoura" || s == "lagarto")
            {
                cout << "sheldon" << endl;
            }
        }
        else if (r == "pedra")
        {
            if (s == "tesoura" || s == "lagarto")
            {
                cout << "rajesh" << endl;
            }
            else if (s == "papel" || s == "spock")
            {
                cout << "sheldon" << endl;
            }
        }
        else if (r == "lagarto")
        {
            if (s == "spock" || s == "papel")
            {
                cout << "rajesh" << endl;
            }
            else if (s == "pedra" || s == "tesoura")
            {
                cout << "sheldon" << endl;
            }
        }
        else if (r == "spock")
        {
            if (s == "pedra" || s == "tesoura")
            {
                cout << "rajesh" << endl;
            }
            else if (s == "lagarto" || s == "papel")
            {
                cout << "sheldon" << endl;
            }
        }

    }
}
