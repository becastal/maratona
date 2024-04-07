#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#define dbg(x) cout << #x << " = " << x << endl;

using namespace std;

int main()
{
    string fita;

    while (getline(cin, fita))
    {
        map<char, char> complemento {{'B', 'S'}, {'S', 'B'}, {'C', 'F'}, {'F', 'C'}};
        stack<char> bases;
        
        int resposta = 0;
        for (int i = 0; i < fita.size(); i++)
        {
            if (!bases.empty() && complemento[bases.top()] == fita[i])
            {
                bases.pop();
                resposta++;
            }
            else
            {
                bases.push(fita[i]);
            }
        }
        cout << resposta << endl;
    }
}