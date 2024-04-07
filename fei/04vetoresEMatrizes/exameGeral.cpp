#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, j;
    while (cin>>i>>j)
    {
        vector<int> notas(i);
        for (int k = 0; k < i; k++)
        {
            cin>>notas[k];
        }

        sort(notas.begin(), notas.end(), greater<int>());

        for (int l = 0; l < j; l++)
        {
            int m;
            cin>>m;
            cout<<notas[m - 1]<<endl;
        }
    }

    return 0;
}
