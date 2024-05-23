#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
    vector<pair<int, bool>> numeros(n, {0, false});
    cin >> numeros[0].first;
    int contagem = 1;
    for (int i = 1; i < n; i++)
    {
        cin >> numeros[i].first;
        if (numeros[i - 1].first != numeros[i].first)
        {
            contagem++;
        }
        else if (numeros[i - 1].second)
        {
            contagem++;
        }
        else
        {
            numeros[i].second == true;
        }
    }
    cout << contagem << endl;
}
