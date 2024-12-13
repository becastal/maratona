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
	friend istream& operator >>(istream& in, m& a) { ll val; in >> val; a = m(val); return in; } friend ostream& operator <<(ostream& out, m a) { return out << a.v; }
	friend m operator +(m a, m b) { return a += b; }
	friend m operator -(m a, m b) { return a -= b; }
	friend m operator *(m a, m b) { return a *= b; }
	friend m operator /(m a, m b) { return a /= b; }
	friend m operator ^(m a, ll e) { return a ^= e; }
};

typedef mod_int<998244353> mint;
int main()
{
    _;

	int n; cin >> n;
	vector<int> v(n);
	for (int& i : v) cin >> i;

	vector dp(n, vector<vector<mint>>(n, vector<mint>(n+1, 0)));

	for (int i = n-1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			dp[i][j][2] += 1;
			for (int l = 2; l < n - i; l++) {
				for (int k = j + 1; k < n; k++) {
					if (v[k] - v[j] != v[j] - v[i]) continue;
					dp[i][j][l+1] += dp[j][k][l];
				}
			}
		}
	}

	vector<mint> res(n+1, 0);
	res[1] = n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int l = 2; l < n - i + 1; l++) {
				res[l] += dp[i][j][l];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << res[i] << " \n"[i==n];
	}
    
    return(0);
}
