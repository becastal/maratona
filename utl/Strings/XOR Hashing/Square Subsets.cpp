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

template<int D> struct gauss_z2 {
	bitset<D> basis[D], keep[D];
	int rk, in;
	vector<int> id;
 
	gauss_z2 () : rk(0), in(-1), id(D, -1) {};
 
	bool add(bitset<D> v) {
		in++;
		bitset<D> k;
		for (int i = D - 1; i >= 0; i--) if (v[i]) {
			if (basis[i][i]) v ^= basis[i], k ^= keep[i];
			else {
				k[i] = true, id[i] = in, keep[i] = k;
				basis[i] = v, rk++;
				return true;
			}
		}
		return false;
	}
	pair<bool, bitset<D>> coord(bitset<D> v) {
		bitset<D> c;
		for (int i = D - 1; i >= 0; i--) if (v[i]) {
			if (basis[i][i]) v ^= basis[i], c[i] = true;
			else return {false, bitset<D>()};
		}
		return {true, c};
	}
	pair<bool, vector<int>> recover(bitset<D> v) {
		auto [span, bc] = coord(v);
		if (not span) return {false, {}};
		bitset<D> aux;
		for (int i = D - 1; i >= 0; i--) if (bc[i]) aux ^= keep[i];
		vector<int> oc;
		for (int i = D - 1; i >= 0; i--) if (aux[i]) oc.push_back(id[i]);
		return {true, oc};
	}
};

const int N = 19;
const int MOD = 1e9 + 7;
typedef mod_int<MOD> mint;

vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67 };
int fb(int x) {
	int res = 0;
	for (int i = 0; i < N; i++) {
		while (x % primes[i] == 0) {
			x /= primes[i];
			res ^= (1 << i);
		}
	}
	return res;
}

int solve() {
	int n; cin >> n;
	vector<int> A(n);

	gauss_z2<20> gz;
	for (int& i : A) cin >> i, gz.add(bitset<20>(fb(i)));
	cout << (mint(2) ^ (n - gz.rk)) - mint(1) << endl;

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
