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
        int a, b, x, y; cin >> a >> b >> x >> y;
        
        int areaCorteHorizontal = max(b - 1 - y, y) * a;
        int areaCorteVertical = max(a - 1 - x, x) * b;

        cout << max(areaCorteHorizontal, areaCorteVertical) << endl;
    }
}
