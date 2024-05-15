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

#define sq(x) ((x)*(x))
int l, c, r1, r2;

bool solve()
{
    int soma = r1 + r2, dl = l - soma, dc = c - soma;
    return 2 * r1 <= min(l, c) && 2 * r2 <= min(l, c) && sq(soma) <= sq(dl) + sq(dc);
}

int main()
{
    _;
    while (true)
    {
        cin >> l >> c >> r1 >> r2;
        if (l == 0 && c == 0 && r1 == 0 && r2 == 0)
            break;

        cout << (solve() ? 'S' : 'N') << endl;
    }

    
    return(0);
}
