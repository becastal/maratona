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

ll f(ll x, ll y)
{
    ll e = 1, d = 1e6, m;
    while (d > e)
    {
        m = e + (d - e) / 2;
        if (y * y + m * m >= x * x)
            d = m;
        else
            e = m + 1;
    }
    return e;
}

int main()
{
    _;
    int t; cin >> t;
    while(t--)
    {
        ll r; cin >> r;
        ll res = 4;
        for (ll i = 1; i <= r; i++)
            res += 4 * (f(r + 1, i) - f(r, i));

        cout << res << endl;
    }
    
    return(0);
}

