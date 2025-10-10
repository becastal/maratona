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

ll gcd(ll a, ll b) {
	if (b > a) swap(a, b);
	return (b ? gcd(b, a % b) : a);
}

ll mul(ll a, ll b, ll m) {
	ll ret = a*b - ll((long double)1/m*a*b+0.5)*m;
	return ret < 0 ? ret+m : ret;
}

ll pow(ll x, ll y, ll m) {
	if (!y) return 1;
	ll ans = pow(mul(x, x, m), y/2, m);
	return y%2 ? mul(x, ans, m) : ans;
}

bool prime(ll n) {
	if (n < 2) return 0;
	if (n <= 3) return 1;
	if (n % 2 == 0) return 0;

	ll r = __builtin_ctzll(n - 1), d = (n-1) >> r;
	for (int a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
		ll x = pow(a, d, n);
		if (x == 1 or x == n - 1 or a % n == 0) continue;

		for (int j = 0; j < r - 1; j++) {
			x = mul(x, x, n);
			if (x == n - 1) break;
		}
		if (x != n - 1) return 0;
	}
	return 1;
}

ll rho(ll n) {
	if (n == 1 or prime(n)) return n;
	auto f = [n](ll x) {return mul(x, x, n) + 1;};

	ll x = 0, y = 0, t = 30, prd = 2, x0 = 1, q;
	while (t % 40 != 0 or gcd(prd, n) == 1) {
		if (x==y) x = ++x0, y = f(x);
		q = mul(prd, abs(x-y), n);
		if (q != 0) prd = q;
		x = f(x), y = f(f(y)), t++;
	}
	return gcd(prd, n);
}

vector<ll> fact(ll n) {
	if (n == 1) return {};
	if (prime(n)) return {n};
	ll d = rho(n);
	vector<ll> l = fact(d), r = fact(n / d);
	l.insert(l.end(), r.begin(), r.end());
	return l;
}

typedef __int128 int128;

int128 ipow(ll base, int exp) {
    int128 result = 1;
    while(exp) {
        if(exp & 1)
            result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}

string toString(int128 x) {
    if (x == 0) return "0";
    string s;
    while(x > 0) {
        s.push_back('0' + (int)(x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

void solve() {
    ll x; 
    cin >> x;

    auto ff = fact(x);
    map<ll, int> f;
    for (ll i : ff) 
        f[i]++;

    int128 res = 1;
    for (auto p : f) {
        ll prime_factor = p.first;
        int exponent = p.second;
        int128 numerator = ipow(prime_factor, exponent + 1) - 1;
        int128 denominator = prime_factor - 1;
        res *= (numerator / denominator);
    }
    int128 ans = res - x;
    cout << toString(ans) << "\n";
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
