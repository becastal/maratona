#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
using namespace std;

ll xs(ll n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1LL;
    if (n % 4 == 2) return n + 1;
    return 0LL;
}
ll xs2(ll n, ll p2, ll m) {
    if (n % 4 == 0) return n * (1LL << p2);
    if (n % 4 == 1) return (1LL << p2) + m;
    if (n % 4 == 2) return (n + 1) * (1LL << p2);
    return m;
}
void solve() {
    ll l, r, p2, m;
    cin >> l >> r >> p2 >> m;

    ll p = 1LL << p2;
    ll small = (l - m) / p;
    if (p * small + m < l) small++;

    ll big = (r - m) / p;
    ll result = xs(r) ^ xs(l - 1) ^ xs2(big, p2, m) ^ xs2(small - 1, p2, m);

    cout << result << endl;
}

int main() {
    _;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

