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

const int MAX = 1e6;
template<int p> struct mod_int {
	ll expo(ll b, ll e) { ll ret = 1; while (e) { if (e % 2) ret = ret * b % p; e /= 2, b = b * b % p; } return ret; }
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
	m& operator ^=(ll e) { if (e < 0) { v = inv(v); e = -e; } v = expo(v, e); }
	bool operator ==(const m& a) { return v == a.v; }
	bool operator !=(const m& a) { return v != a.v; }
	friend istream& operator >>(istream& in, m& a) { ll val; in >> val; a = m(val); return in; }
	friend ostream& operator <<(ostream& out, m a) { return out << a.v;
	}
	friend m operator +(m a, m b) { return a += b; }
	friend m operator -(m a, m b) { return a -= b; }
	friend m operator *(m a, m b) { return a *= b; }
	friend m operator /(m a, m b) { return a /= b; }
	friend m operator ^(m a, ll e) { return a ^= e; }
};
typedef mod_int<(int)1e7+7> mint;

int divi[MAX+1];
void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;
}

mint g(int n) {
    mint ans = 1;
    for (int p = 2; p <= n; p++) {
        if (divi[p] != p) continue;

		ll exp = 0;
		for (ll j = p; j <= n; j *= p)
			exp += n / j;
		ans *= mint((exp + 2) * (exp + 1) / 2);
    }
    return ans;
}

int main()
{
    _;

	crivo(MAX);
	int x; 
	while (cin >> x and x) {
		cout << g(x) << endl;
	}
    
    return(0);
}
