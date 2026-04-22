#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

void xadrez(vector<vector<bool>>& matriz)
{
    for (int i = 0; i < matriz.size(); i++)
        for (int j = 0; j < matriz[i].size(); j++)
            if ((i + j) % 2 == 0) matriz[i][j] = true;
}

void pilares(vector<vector<bool>>& matriz)
{
    for (int i = 0; i < matriz.size(); i++)
        for (int j = 0; j < matriz[i].size(); j++)
            if (j % 2 == 0) matriz[i][j] = true;

    matriz[0][1] = true;
}

int main()
{
    _;
    int t; cin >> t;

    while (t--)
    {
        int n, m; cin >> n >> m;
        vector<vector<bool>> matriz(n, vector<bool>(m, false));

        if (n % 2 == 1 && m % 2 == 1)
            xadrez(matriz);
        else if (n % 2 == 0 && m % 2 == 0)
            pilares(matriz);
        else    
        {
            xadrez(matriz);
            matriz[n-1][m-1] = true;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << (matriz[i][j] ? "B" : "W");
            cout << endl;
        }
    }

    return 0;
}