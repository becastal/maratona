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
        int x, n, m; cin >> x >> n >> m;
        
        while (n > 0 || m > 0)
        {
            if (n >= 0 && x / 2 + 10 < x - 10)
                n--, x = x / 2 + 10;
            else if (m >= 0 && x - 10 < x / 2 + 10)
                m--, x = x - 10;
            else if (m == 0 && n >= 0)
                n--, x = x / 2 + 10;
            else if (n == 0 && m >= 0)
                m--, x = x - 10;
        }
        
        cout << (x > 0 ? "NO" : "YES") << endl;
   } 
    return(0);
}
