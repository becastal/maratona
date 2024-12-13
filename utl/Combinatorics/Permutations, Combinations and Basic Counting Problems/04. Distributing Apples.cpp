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

const int mod = 1e9 + 7;
const int maxn = 4e6 + 10;

ll exp(ll x, ll n, ll m) {
    x %= m;
    ll res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = res * x % m;
        }
        x = x * x % m;
        n /= 2;
    }
    return res;
}

int main() {
    _;

    vector<ll> fat(maxn, 1), invfat(maxn, 1);
    for (int i = 1; i < maxn; i++) {
        fat[i] = fat[i - 1] * i % mod;
    }

    invfat[maxn - 1] = exp(fat[maxn - 1], mod - 2, mod);
    for (ll i = maxn - 1; i > 0; i--) {
        invfat[i - 1] = invfat[i] * i % mod;
    }

	int n, m; cin >> n >> m; n--;
	ll res = fat[n+m] * invfat[n] % mod * invfat[m] % mod;

    cout << res << endl;

    return 0;
}

