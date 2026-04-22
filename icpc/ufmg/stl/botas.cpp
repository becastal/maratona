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

int main()
{
    int n;

    while (cin >> n)
    {
        vector<pair<int, int>> botas(31, {0, 0});
        for (int i = 0; i < n; i++)
        {
            int tamanho; cin >> tamanho;
            char pe; cin >> pe;

            if (pe == 'E')
                botas[tamanho - 30].f++;
            else
                botas[tamanho - 30].s++;
        }

        int totalDePares = 0;
        for (int i = 0; i < 31; i++)
            totalDePares += min(botas[i].first, botas[i].second);
        
        cout << totalDePares << endl;
    }

    return(0);
}