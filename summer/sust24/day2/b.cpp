#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

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

const int MAX = 2e5+10;
namespace seg {
	struct nodo {
		mint a, b;
		nodo() : a(1), b(0) {};
		nodo(mint a_, mint b_) : a(a_), b(b_) {};
		nodo friend operator + (nodo eu, nodo outro) {
			return nodo(eu.a * outro.a, outro.a * eu.b + outro.b);
		}
		nodo& operator +=(const nodo& outro) {
			a = a * outro.a;
			b = outro.a * b + outro.b;
			return *this;
		}
	};

	nodo seg[4*MAX], lazy[4*MAX];
	int n, *v;

	nodo build(int p=1, int l=0, int r=n-1) {
		lazy[p] = nodo();
		if (l == r) return seg[p] = nodo();
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void prop(int p, int l, int r) {
		seg[p] += lazy[p];
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = nodo();
	}
	nodo query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return nodo();
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	nodo update(int a, int b, nodo x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) + update(a, b, x, 2*p+1, m+1, r);
	}
};

int solve() {
	int n, q; cin >> n >> q;
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	seg::n = n;
	seg::build();

	for (int i = 0, l, r, x; i < q; i++) {
		cin >> l >> r >> x; l--, r--;

		mint tam = r - l + 1;
		mint a = (tam - 1) / tam;
		mint b = x / tam;
		
		seg::update(l, r, seg::nodo(a, b));

		//for (int j = l; j <= r; j++) {
		//	A[j] = inv(tam) * (((tam - 1) * A[j] % mod + x) % mod) % mod;
		//}
	}

	for (int i = 0; i < n; i++) {
		seg::nodo res = seg::query(i, i);
		cout << A[i] * res.a + res.b << " \n"[i==n-1];
	}

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

