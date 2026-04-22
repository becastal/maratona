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

bool solve(string& a, string& b, string& c)
{
    for (int i = 0; i < a.size(); i++)
        if ( (a[i] != b[i] && c[i] != a[i] && c[i] != b[i]) || (a[i] == b[i] && c[i] != a[i]) )
            return false;

    return true;
}


int main()
{
    _;
    int t; cin >> t;

    while (t--)
    {
        string a, b, c;
        cin >> a >> b >> c;
        
        cout << (solve(a, b, c) ? "YES" : "NO") << endl;
    }

    return 0;
}