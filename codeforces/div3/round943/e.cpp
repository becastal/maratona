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

void solve()
{
    int n; cin >> n;
    if (n == 2)
    {
        cout << "1 1" << endl << "1 2" << endl;
        return;
    }
    if (n == 3)
    {
        cout << "2 1" << endl << "2 3" << endl << "3 1" << endl;
        return;
    }
    for (int i = 3; i <= n; i++)
        cout << n << " " << i << endl;

    cout << "1 1" << endl;
    cout << "2 " << n << endl;
}

int main()
{
    _;

    int t; cin >> t;
    while (t--)
        solve();

    return(0);
}
