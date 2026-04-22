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
        
        while (x > 0 && n && x / 2 + 10 < x)
            n--, x = x / 2 + 10;

        cout << (x <= m * 10 ? "YES" : "NO") << endl;
   } 
    return(0);
}