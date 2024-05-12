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

    int r1, x1, y1, r2, x2, y2;
    while (cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2)
    {
        double distCentros = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        
        cout << ( distCentros + r2 <= r1  ? "RICO" : "MORTO") << endl;
    }

    return(0);
}
