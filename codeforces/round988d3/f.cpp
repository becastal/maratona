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

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> h(n), x(n);

    for (int& i : h) cin >> i;
    for (int& i : x) cin >> i;

    ll l = 1, r = (ll)1e9 + 10;

    auto da = [&] (ll mi) {
        map<ll, ll> M;
        for (int i = 0; i < n; i++) {
            int xi = (h[i] + mi - 1) / mi;
            if (xi > m) continue;

			M[x[i]-m+xi]++;
			M[x[i]+m-xi+1]--;
        }
        ll num = 0;
        for (auto [a, b] : M) {
            num += b;
            if (num >= k) return 1;
        }
        return 0;
    };

    while (l < r) {
        ll mi = l+r>>1;
        if (da(mi)) r = mi;
        else l = mi + 1;
    }

    if (r == (ll)1e9 + 10) {
        cout << -1 << endl;
        return;
    }
    cout << r << endl;
}

int main() {
    _;

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

