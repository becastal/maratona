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

    auto f = [&](auto&& f, int n, int m, int& res) {
        if (res) return;
        if (n == m) {
            res = true;
            return;
        }
        if (n % 3 != 0) return;

        f(f, n / 3 * 2, m, res);
        f(f, n / 3, m, res);
    };

    int t; cin >> t;
    while (t--) {
        int n, m, res = 0; cin >> n >> m;
        f(f, n, m, res);
        cout << (res ? "YES" : "NO") << endl;
    }
    
    return 0;
}

