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
    unsigned int a, b;
    while (cin >> a >> b)
    {
        if (a < b) swap(a, b);

        unsigned int mp = 1;
        while (mp < a) mp << 1;

        unsigned int r = a + b;
        if (r > mp) r -= mp;
        cout << r << endl;
    }

    return(0);
}
