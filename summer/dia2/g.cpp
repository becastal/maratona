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

	ll n, k; cin >> n >> k;
	if (k == 1) return cout << n << endl, 0;
	if (k > n / 2) return cout << 0 << endl, 0;
	if (n & 1 ^ 1 and k == n / 2) return cout <<  fat[k] * 2LL % mod << endl, 0;
	//if (k == 1) { cout << n << endl; continue; }
	//if (k > n / 2) { cout << 0 << endl; continue; }
	//if (n & 1 ^ 1 and k == n / 2) { cout << fat[k] * 2LL % mod << endl; continue; }

	ll res = fat[k] * esc(n-k-1, k) % mod;
	res = (res + (fat[k] * (2LL*esc(n-k-1, k-1) % mod))) % mod;
	cout << res << endl;

	return 0;
}
