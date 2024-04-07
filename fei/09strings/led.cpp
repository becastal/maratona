#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string num;
        cin >> num;

        int leds = 0;
        for (int j = 0; j < num.size(); j++)
        {
            if (num[j] == '1')
            {
                leds += 2;
            }
            else if (num[j] == '2' || num[j] == '3' || num[j] == '5')
            {
                leds += 5;
            }
            else if (num[j] == '4')
            {
                leds += 4;
            }
            else if (num[j] == '6' || num[j] == '9' || num[j] == '0')
            {
                leds += 6;
            }
            else if (num[j] == '7')
            {
                leds += 3;
            }
            else if (num[j] == '8')
            {
                leds += 7;
            }
        }
        cout << leds << " leds" << endl;
    }
}
