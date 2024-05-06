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
    
    ll t; cin >> t;

    while (t--)
    {
        ll x, y; cin >> x >> y;
        ll a, b; cin >> a >> b;
        
        b = min(2 * a, b);

        if (x < y) 
            swap(x, y);

        cout << (y * b + (x - y) * a) << endl;
    }

    return(0);
}