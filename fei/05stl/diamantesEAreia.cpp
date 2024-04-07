#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n; cin >> n;
    
    
    for (int i = 0; i < n; i++)
    {
        string mina;
        cin >> mina;
        
        stack<bool> minerador;
        int diamantes = 0;
        for (int j = 0; j < mina.size(); j++)
        {
            if (mina[j] == '<') 
                minerador.push(true);
            else if (mina[j] == '>' && !minerador.empty())
            {
                minerador.pop();
                diamantes++;
            }
        }
        
        cout << diamantes << endl;
    }
}

