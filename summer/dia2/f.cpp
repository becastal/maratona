#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;
vector<ll> fat(maxn, 1), invfat(maxn, 1);
 
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

ll esc(ll a, ll b) {
	return fat[a] * invfat[b] % mod * invfat[a-b] % mod;
}
 
int main() {
    _;
 
    for (ll i = 1; i < maxn; i++) {
        fat[i] = fat[i - 1] * i % mod;
    }
 
	invfat[maxn - 1] = exp(fat[maxn - 1], mod-2, mod);
    for (ll i = maxn - 1; i > 0; i--) {
        invfat[i - 1] = invfat[i] * i % mod;
    }

	ll n; cin >> n;
	ll res = 0;
	for (ll i = 1; i <= n; i++) {
		res = (res + ((i & 1 ? 1LL : -1LL) * (esc(n, i) * fat[n-i] % mod) + mod) % mod) % mod;
	}
	//cout << res << endl;
	cout << res * invfat[n] % mod << endl;

	return 0;
}
