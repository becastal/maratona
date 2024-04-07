#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    while (true)
    {
        int i; cin >> i;
        if (i == 0) break;

        queue<int> cartas;
        for (int j = 0; j < i; j++)
        {
            cartas.push(j + 1);
        }

        cout << "Discarded cards: ";
        while (cartas.size() > 1)
        {
            cout << cartas.front();
            if (cartas.size() != 2) cout << ", ";
            cartas.pop();
            cartas.push(cartas.front());
            cartas.pop();
        }
        cout << endl << "Remaining card: " << cartas.front() << endl;
    }
}

