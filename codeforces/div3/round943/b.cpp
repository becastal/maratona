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
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;

    int i = 0;
    for (auto c : b)
        if (i < n && c == a[i])
            i++;

    cout << i << endl;
}

int main()
{
    _;
    int t; cin >> t;

    while (t--)
        solve();

    return(0);
}