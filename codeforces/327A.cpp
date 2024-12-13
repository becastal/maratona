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

    int n; cin >> n;
    vector<int> v(n);

    int res = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        res += x;
        v[i] = (x ? -1 : 1);
    }

    if (res == n) return cout << res - 1 << endl, 0;

    int soma = -INF, agora = 0;
    for (int i = 0; i < n; i++) {
        agora += v[i];
        agora = max(0, agora);
        soma = max(soma, agora);
    }

    cout << res + soma << endl;

    return(0);
}
