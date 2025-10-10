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

const int MAX = 2e5+10;
const int mod = 1e9+7;

vector<ll> fat(MAX, 1), invfat(MAX, 1);

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

ll esc(int n, int k) {
	if (k > n) return 0;
	return fat[n] * invfat[k] % mod * invfat[n-k] % mod;
}

void solve() {
	int n, k; cin >> n >> k;
	vector<int> v(n), f(2, 0);
	for (int i : v) cin >> i, f[i]++;

	ll res = 0;
	for (int i = k/2+1; i <= k; i++) {
		res += esc(f[1], i) * esc(f[0], k - i) % mod;
		res %= mod;
	}

	cout << res << endl;
}

int main()
{
    _;

	for (ll i = 2; i < MAX; i++) {
		fat[i] = fat[i-1]*i % mod;
	}

    invfat[MAX - 1] = exp(fat[MAX - 1], mod - 2, mod);
    for (ll i = MAX - 1; i > 0; i--) {
        invfat[i - 1] = invfat[i] * i % mod;
    }

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
