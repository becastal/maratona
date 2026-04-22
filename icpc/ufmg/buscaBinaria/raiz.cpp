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

    double n; cin >> n;
    double l = 0, r = 1e8;

    for (int i = 0; i < 1000; i++)
    {
        double m = (l + r) / 2;

        if (m * m > n)
            r = m;
        else
            l = m;
    }

    cout << fixed << setprecision(10) << (l + r) / 2 << endl;

    return(0);
}
