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

ll cubica(ll x) {
    ll l = 0, r = 1e6, m;
    while (l < r) {
        m = (l + r + 1) / 2;
        if (m * m * m <= x) l = m;
        else r = m - 1;
    }
    return l;
}

void solve() {
    ll p; cin >> p;
    vector<ll> res;

    ll limit = cubica(2 * (p - 1));

    for (ll b = 1; b <= limit; b++) {
        ll b1 = b + 1, b2 = b + 2;
        if (2 * (p - 1) % (b1 * b2) == 0) {
            ll k = 2 * (p - 1) / (b1 * b2);
            
            if (k <= limit) {
                res.push_back(b);
            }
        }
    }

    cout << res.size() << endl;
    for (ll i : res) cout << i << ' ';
    cout << endl;
}

int main() {
    _;
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

