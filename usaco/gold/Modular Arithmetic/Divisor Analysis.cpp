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
	m& operator ^=(ll e) { if (e < 0) { v = inv(v); e = -e; } v = expo(v, e); return *this; }
	bool operator ==(const m& a) { return v == a.v; }
	bool operator !=(const m& a) { return v != a.v; }
 
	friend istream& operator >>(istream& in, m& a) {
		ll val; in >> val;
		a = m(val);
		return in;
	}
	friend ostream& operator <<(ostream& out, m a) {
		return out << a.v;
	}
	friend m operator +(m a, m b) { return a += b; }
	friend m operator -(m a, m b) { return a -= b; }
	friend m operator *(m a, m b) { return a *= b; }
	friend m operator /(m a, m b) { return a /= b; }
	friend m operator ^(m a, ll e) { return a ^= e; }
};
 
const int mod = 1e9+7;
typedef mod_int<(int)1e9+7> mint;
typedef mod_int<(int)(2e9+12)> expmint;
 
int main()
{
    _;
 
	int n; cin >> n;
	
	mint a = 1, b = 1, c = 1;
    expmint d_count_mod2 = 1;
    bool even_div_count = false;
    
    vector<pair<int, int>> v(n);
    for (auto& [p, k] : v) {
		cin >> p >> k;
 
        a *= mint(k + 1);
        int factor = k + 1;
        d_count_mod2 *= expmint(factor);
        if (factor % 2 == 0)
            even_div_count = true;
    }
    
    for (auto [p, k] : v) {
        mint pm = mint(p);
        mint S = (pm ^ (k + 1)) - mint(1);
        S /= (pm - mint(1));
        b *= S;
    }
    
    mint n_mod = 1, sqrt_n = 1;
    for (auto [p, k] : v) {
        mint pm = mint(p);
        n_mod *= (pm ^ k);
        sqrt_n *= (pm ^ (k / 2));
    }
    
    if (even_div_count) {
        ll exp = (d_count_mod2.v / 2) % (mod - 1);
        c = n_mod ^ exp;
    } else {
        ll exp = d_count_mod2.v % (mod - 1);
        c = sqrt_n ^ exp;
    }
 
	cout << a << ' ' << b << ' ' << c << endl;
    
    return(0);
}
