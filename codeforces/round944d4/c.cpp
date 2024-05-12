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

bool solve()
{
    int a, b, c, d; cin >> a >> b >> c >> d;
    int maior1 = max(a, b), maior2 = max(c, d);
    int menor1 = min(a, b), menor2 = min(c, d);
    set<int> pode;

    for (int i = 1; i <= 12; i++)
        if (i < menor1 || i > maior1)
            pode.insert(i);

    if (pode.count(c) == pode.count(d))
        return false;
    else
        return true;
}

int main()
{
    _;
    int t; cin >> t;
    while (t--)
        cout << (solve() ? "YES" : "NO") << endl; 

    return(0);
}
