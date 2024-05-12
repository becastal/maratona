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
        ll n, res; cin >> n;
        res = 1;
        for (ll i = 1; i <= n; i++)
            res += ((ll)sqrt((n+1)*(n+1)-i*i-1)-(ll)sqrt(n*n-i*i-1));
        
        cout << 4 * res << endl;
    }

    return(0);
}
