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
const int maxn = 2e6 + 10;

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

int main()
{
    _;

    vector<ll> fat(maxn, 1), invfat(maxn, 1);
    for (int i = 1; i < maxn; i++) {
        fat[i] = fat[i - 1] * i % mod;
    }

    invfat[maxn - 1] = exp(fat[maxn - 1], mod - 2, mod);
    for (ll i = maxn - 1; i > 0; i--) {
        invfat[i - 1] = invfat[i] * i % mod;
    }

	int a, b, n; cin >> a >> b >> n;

	auto good = [&] (int x) {
		int ok = 1;
		while (x and ok) {
			ok &= x % 10 == a or x % 10 == b;	
			x /= 10;
		}
		return ok;
	};

	auto perm = [&] (int x) {
		return fat[n] * invfat[x] % mod * invfat[n-x] % mod;
	};

	ll res = 0;
	for (int i = 0; i <= n; i++) {
		if (good(i * a + (n - i) * b)) {
			res = (res + perm(i)) % mod;
		}
	}
	cout << res << endl;
    
    return(0);
}
