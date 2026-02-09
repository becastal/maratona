#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

// Aritmetica Modular
//
// O mod tem q ser primo

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
	mod_int(ll v_) {
		if (v_ >= p or v_ <= -p) v_ %= p;
		if (v_ < 0) v_ += p;
		v = v_;
	}
	m& operator +=(const m& a) {
		v += a.v;
		if (v >= p) v -= p;
		return *this;
	}
	m& operator -=(const m& a) {
		v -= a.v;
		if (v < 0) v += p;
		return *this;
	}
	m& operator *=(const m& a) {
		v = v * ll(a.v) % p;
		return *this;
	}
	m& operator /=(const m& a) {
		v = v * inv(a.v) % p;
		return *this;
	}
	m operator -(){ return m(-v); }
	m& operator ^=(ll e) {
		if (e < 0) {
			v = inv(v);
			e = -e;
		}
		v = expo(v, e);
		// possivel otimizacao:
		// cuidado com 0^0
		// v = expo(v, e%(p-1)); 
		return *this;
	}
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
typedef mod_int<998244353> mint;

struct Dsu {
	int n;
	vector<int> id, sz;
	vector<mint> exp, sobra;
	Dsu(int n_) : n(n_), id(n), sz(n, 1), exp(n, 0), sobra(n, 0) {
		iota(all(id), 0);
	}

	int find(int i) {
		return id[i] == i ? i : find(id[i]);
	}

	int merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return 0;
		if (sz[i] < sz[j]) swap(i, j);
		sz[i] += sz[j], id[j] = i;
		sobra[j] = exp[i];
		return 1;
	}

	void add(int i, mint x) {
		exp[find(i)] += x;
	}

	mint get(int i) {
		mint res = exp[i];
		if (i == id[i]) return res;
		res += get(id[i]) - sobra[i];
		return res;
	}
};

int solve() {
	int n; cin >> n;
	Dsu dsu(n);

	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v; u--, v--;
		int szu = dsu.sz[dsu.find(u)], szv = dsu.sz[dsu.find(v)];
		dsu.add(u, mint(szu) / mint(szu + szv));
		dsu.add(v, mint(szv) / mint(szu + szv));
		dsu.merge(u, v);
	}

	for (int i = 0; i < n; i++) {
		cout << dsu.get(i) << " \n"[i==n-1];
	}

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

