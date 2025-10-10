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

	friend istream& operator >>(istream& in, m& a) { ll val; in >> val; a = m(val); return in; }
	friend ostream& operator <<(ostream& out, m a) { return out << a.v; }
	friend m operator +(m a, m b) { return a += b; }
	friend m operator -(m a, m b) { return a -= b; }
	friend m operator *(m a, m b) { return a *= b; }
	friend m operator /(m a, m b) { return a /= b; }
	friend m operator ^(m a, ll e) { return a ^= e; }
};
typedef mod_int<(int)1e9+7> mint;

const int MAX = 2e5+10;
mint fat[MAX], invfat[MAX];

mint C(int n, int k) {
	if (n < k) return mint(0);
	return fat[n] * invfat[k] * invfat[n-k];
}

int solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> a(n), f(n);

	for (int& i : a) cin >> i, f[i-1]++;
	sort(a.begin(), a.end());

	mint res(0);
	for (int l = 0, r = 0; l < n; l++) {
		while (r < n and a[r] - a[l] <= k) r++;
		res += C(r - l - 1, m - 1);
	}
	cout << res << endl;
	
	return(0);
}

int main()
{
    _;

	fat[0] = invfat[0] = mint(1);
    for (int i = 1; i < MAX; i++) {
        fat[i] = fat[i-1] * i;
    }
 
    invfat[MAX - 1] = fat[MAX-1] ^ int(1e9+5);
    for (ll i = MAX - 1; i > 0; i--) {
        invfat[i-1] = invfat[i] * i;
    }

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
