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
    _;
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;

        pair<int, int> branca;
        cin >> branca.f >> branca.s;

        int id;
        int menor = INF;

        for (int i = 0; i < n; i++)
        {
            int x, y; cin >> x >> y;
            int dquad = pow(branca.f - x, 2) + pow(branca.s - y, 2);
            if (dquad < menor)
                id = i + 1, menor = dquad;
        }
        cout << id << endl;
    }
    
    return(0);
}
