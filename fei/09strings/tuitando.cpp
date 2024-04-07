#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int totalCaracteres = 0;

    string s;
    getline(cin, s);
    while (s != "")
    {
        totalCaracteres += s.size();
        getline(cin, s);
    }

    if (totalCaracteres <= 140)
    {
        cout << "TWEET" << endl;
    }
    else
    {
        cout << "MUTE" << endl;
    }
}
