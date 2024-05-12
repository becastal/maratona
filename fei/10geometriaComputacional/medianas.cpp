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

    double m1, m2, m3;
    while (cin >> m1 >> m2 >> m3)
    {
        double s = (m1 + m2 + m3) / 2;
        double resp = s * (s - m1) * (s - m2) * (s - m3); 
        cout << fixed << setprecision(3) << (resp > 0 ? 4.0 * sqrt(resp) / 3.0 : -1.0) << endl;
    }

    return(0);
}
