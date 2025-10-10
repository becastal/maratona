#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

template<typename T = int> struct frac {
	T num, den;
	template<class U, class V>
	frac(U num_ = 0, V den_ = 1) : num(num_), den(den_) {
		assert(den != 0);
		if (den < 0) num *= -1, den *= -1;
		T g = gcd(abs(num), den);
		num /= g, den /= g;
	}

	friend bool operator<(const frac& l, const frac& r) {
		return __int128(l.num) * r.den < __int128(r.num) * l.den;
	}
	friend frac operator+(const frac& l, const frac& r) {
		return {l.num*r.den + l.den*r.num, l.den*r.den};
	}
	friend frac operator-(const frac& l, const frac& r) {
		return {l.num*r.den - l.den*r.num, l.den*r.den};
	}
	friend frac operator*(const frac& l, const frac& r) {
		return {l.num*r.num, l.den*r.den};
	}
	friend frac operator/(const frac& l, const frac& r) {
		return {l.num*r.den, l.den*r.num};
	}
	friend ostream& operator<<(ostream& out, frac f) {
		out << f.num << ' ' << f.den;
		return out;
	}
};

const int MAX = 5e5+10;
namespace seg {
	struct nodo {
		ll mx, mn, dd;
		frac<ll> ddp;

		nodo() : mx(LLONG_MIN), mn(LLONG_MAX), dd(0), ddp(frac<ll>(0LL, 1LL)) {};
		nodo(ll x) : mx(x), mn(x), dd(0), ddp(frac<ll>(0LL, 1LL)) {};
		friend nodo operator +(nodo a, nodo b) {
			if (a.mn == LLONG_MAX) return b;
			if (b.mn == LLONG_MAX) return a;

			nodo c;
			ll d = max(0LL, a.mx - b.mn);
			c.mx = max(a.mx, b.mx);
			c.mn = min(a.mn, b.mn);
			c.dd = max({a.dd, b.dd, d});
			c.ddp = max({a.ddp, b.ddp, frac<ll>(d, a.mx)});
			return c;
		};
	};

	int n, *v;
	nodo seg[4*MAX];
	nodo build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = nodo(v[l]);
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n_, int* v_) {
		n = n_, v = v_;
		build();
	}
	nodo query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return nodo();
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
}

int solve() {
	int n; cin >> n;

	vector<int> A(n);
	for (int& i : A) cin >> i;
	seg::build(n, A.data());

	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r; l--, r--;
		seg::nodo res = seg::query(l, r);
		cout << res.dd << ' ' << res.ddp << endl;
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

