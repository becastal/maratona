#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

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

	ll r = __builtin_ctzll(n - 1), d = n >> r;
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

vector<array<ll, 2>> fact_(ll n) {
	vector<ll> f = fact(n);
	sort(all(f));

	vector<array<ll, 2>> F;
	for (ll i : f) {
		if (F.empty() or i != F.back()[0]) F.push_back({i, 1});
		else F.back()[1]++;
	}
	return F;
}

int solve() {
	int m, n, k; cin >> m >> n >> k;
	vector<ll> A(n), B(m);
	for (ll& i : A) cin >> i;

	vector<vector<array<ll, 2>>> F(n);

	for (int i = 0, a, b, d; i < k; i++) {
		cin >> a >> b >> d; a--, b--;
		F[b].push_back({a, d});
	}

	for (vector<array<ll, 2>>& V : F) {
		sort(all(V));
	}

	for (int i = 0; i < n; i++) {
		vector<array<ll, 2>> Fa = fact_(A[i]);	

		for (int j = 0; j < (int)Fa.size(); j++) {
			auto [a, d] = F[i][j];
			auto [p, e] = Fa[j];
			B[a] = p;
		}
	}

	for (ll i : B) cout << i << ' '; cout << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

