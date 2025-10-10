#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

template<int p> struct mod_int {
	ll expo(ll b, ll e) {
		ll ret = 1;
		while (e) {
			if (e % 2) ret = ret * b % p;
			e /= 2, b = b * b % p;
		}
		return ret;
	}
	ll inv(ll b) { return expo(b, p-2); }

	using m = mod_int;
	int v;
	mod_int() : v(0) {}
	mod_int(ll v_) { if (v_ >= p or v_ <= -p) v_ %= p; if (v_ < 0) v_ += p; v = v_; }
	m& operator +=(const m& a) { v += a.v; if (v >= p) v -= p; return *this; }
	m& operator -=(const m& a) { v -= a.v; if (v < 0) v += p; return *this; }
	m& operator *=(const m& a) { v = v * ll(a.v) % p; return *this; }
	m& operator /=(const m& a) { v = v * inv(a.v) % p; return *this; }
	m operator -(){ return m(-v); }
	m& operator ^=(ll e) { if (e < 0) { v = inv(v); e = -e; } v = expo(v, e); return *this; }
	bool operator ==(const m& a) { return v == a.v; }
	bool operator !=(const m& a) { return v != a.v; }

	friend istream& operator >>(istream& in, m& a) { ll val; in >> val; a = m(val); return in; }
	friend ostream& operator <<(ostream& out, m a) { return out << a.v; }
	friend m operator +(m a, m b) { return a += b; }
	friend m operator -(m a, m b) { return a -= b; }
	friend m operator *(m a, m b) { return a *= b; }
	friend m operator /(m a, m b) { return a /= b; }
	friend m operator ^(m a, ll e) { return a ^= e; }
};
typedef mod_int<998244353> mint;

const int MAX = 5e5+10;
mint fact[MAX], invfact[MAX];
mint dp[26*MAX];

int solve() {
	vector<int> C(26);
	for (int& i : C) cin >> i;

	int s = accumulate(all(C), 0);
	for (int i = 0; i <= s; i++) dp[i] = 0;
	dp[0] = 1;

	for (int i = 0; i < 26; i++) {
		if (!C[i]) continue;
		for (int j = s; j >= C[i]; j--) {
			dp[j] += dp[j-C[i]];
		}
	}

	mint den = 1;
	for (int i = 0; i < 26; i++) den *= invfact[C[i]];
	cout << fact[(s + 1) / 2] * fact[(s / 2)] * dp[(s + 1) / 2] * den << endl;

	return(0);
}

int main()
{
    _;

	fact[0] = 1;
	for (int i = 1; i < MAX; i++) {
		fact[i] = fact[i-1] * i;
	}

	invfact[MAX-1] = fact[MAX-1] ^ (998244353 - 2);
	for (int i = MAX-1; i >= 1; i--) {
		invfact[i-1] = invfact[i] * i;
	}

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
