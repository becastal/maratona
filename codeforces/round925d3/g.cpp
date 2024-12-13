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
const int mod = 998244353;

ll pow_mod(ll x, ll p) {
    if (p == 0) {
        return 1;
    }
    if (p % 2 == 0) {
        ll y = pow_mod(x, p / 2);
        return (y * y) % mod;
    }
    return (x * pow_mod(x, p - 1)) % mod;
}
 
ll inv(ll x) {
    return pow_mod(x, mod - 2);
}
 
vector<ll> fact = {1};
 
ll cnk(ll n, ll k) {
    ll res = fact[n];
    res = (res * inv(fact[k])) % mod;
    res = (res * inv(fact[n - k])) % mod;
    return res;
}
 
ll calc(int n1, int n2, int n3, int n4) {
    return (cnk(n1 + n3 - 1, n3) * cnk(n2 + n4 - 1, n4)) % mod;
}

int solve() {
	int c1, c2, c3, c4;
	cin >> c1 >> c2 >> c3 >> c4;

	if (c1 + c2 == 0) return cout << (c3 == 0 or c4 == 0 ? 1 : 0) << endl, 0; 
	if (abs(c1 - c2) > 1) return cout << 0 << endl, 0;

	ll res = 0;
	if (c1 <= c2) {
		res += calc(c1 + 1, c2, c3, c4);
	}
	if (c2 <= c1) {
		res += calc(c1, c2 + 1, c3, c4);
	}
	cout << res % mod << endl;
	return 0;
}

int main()
{
    _;

	for (ll i = 1; i <= 4e6; i++) {
		fact.push_back((fact.back() * i) % mod);
	}

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
