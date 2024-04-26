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

int solve(int a, int b)
{
    if (a == b) return 0;
    if (a > b)
    {
        if ((a - b) % 2 == 0)
            return 1;
        else
            return 2;
    }
    else
    {
        if ((a - b) % 2 == 1)
            return 1;
        else
            return 2;
    }
}

int main()
{
    _;
    int t; cin >> t;
    while (t--)
    {
        int a, b; cin >> a >> b;
        cout << solve(a, b) << endl;
    }
}
