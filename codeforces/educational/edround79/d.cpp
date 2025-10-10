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
typedef mod_int<998244353> mint;

int solve() {
	int n; cin >> n;
	vector<vector<int>> v(n);
	map<int, int> fy;

	mint num = 0, den = 0;
	for (auto& s : v) {
		int k; cin >> k;
		s = vector<int>(k);
		
		for (int& i : s) {
			cin >> i;
			fy[i]++;
		}
	}

//	for (int x = 0; x < n; x++) {
//		for (int y : v[x]) {
//			for (int z = 0; z < n; z++) {
//				printf("%d: (%d, %d, %d)\n", int(find(v[z].begin(), v[z].end(), y) != v[z].end()), x, y, z);
//			}
//		}
//	}

	mint res = 0;
	for (auto& s : v) {
		for (int& y : s) {
			res += fy[y] / (mint(s.size()));
		}
	}
	cout << res / (mint(n) * mint(n)) << endl;
	//dbg(mint(7) / mint(8));

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
