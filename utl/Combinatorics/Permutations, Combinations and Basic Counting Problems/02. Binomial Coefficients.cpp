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
 
ll exp(ll x, ll n, ll m) {
	x %= m;
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}
 
 
int main()
{
    _;
	const int maxn = 1e6 + 10;
	const int mod = 1e9 + 7;
	ll fac[maxn + 1], inv[maxn + 1];
 
	fac[0] = 1;
	for (int i = 1; i <= maxn; i++) fac[i] = fac[i-1] * i % mod;
 
	inv[maxn] = exp(fac[maxn], mod - 2, mod);
	for (int i = maxn; i >= 1; i--) {
		inv[i-1] = inv[i] * i % mod;
	}
 
	auto escolhe = [&] (int n, int r) {
		return fac[n] * inv[r] % mod * inv[n-r] % mod;
	};
 
	int n; cin >> n;
	for (int i = 0, a, b; i < n; i++) {
		cin >> a >> b;
		cout << escolhe(a, b) << endl;
	}
 
    return(0);
}
