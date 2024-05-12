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

    ll fp, fh, cont = 0;
    while (cin >> fp >> fh)
    {
        cout << "Molecula #" << ++cont << ".:." << endl;
        ll f = fp + fh;
        ll a = ((5 * fp) + (6 * fh)) / 2;
        ll v = a - f + 2;
        cout << "Possui " << v << " atomos e " << a << " ligacoes" << endl << endl;
    }


    return(0);
}
