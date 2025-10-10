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

	ll n, x; cin >> n >> x;
	ll soma = 0, h = LINF, u = LINF, d = LINF;
    for (int i = 0; i < n; ++i) {
        ll U, D; cin >> U >> D;
        soma += U + D;
        u = min(u + x, U);
        d = min(d + x, D);
        h = min(h, u + d);
    }
    cout << soma - h * n << endl;

    return(0);
}
