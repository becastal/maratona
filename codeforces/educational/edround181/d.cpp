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

const int MAX = 2e5+10;
namespace seg {
	struct nodo {
		int mx, mn;
		nodo() : mx(-INF), mn(INF) {};
		nodo(int x) : mx(x), mn(x) {};
		nodo(int x, int y) : mx(x), mn(y) {};
		nodo friend operator + (nodo a, nodo b) {
			return nodo(max(a.mx, b.mx), min(a.mn, b.mn));
		};
	};
	nodo seg[4*MAX];
	int n, *v;

	nodo build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	nodo query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return nodo();
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
};

int solve() {
	int n, m; cin >> n >> m;

	vector<array<int, 4>> A(n);
	vector<int> P(m+1, 0);
	for (auto& [l, r, p, q] : A) {
		cin >> l >> r >> p >> q; l--, r--;
		P[l]++, P[r+1]--;
	}

	for (int i = 1; i < m; i++) {
		P[i] += P[i-1];
	}
	seg::build(m, P.data());

	if (seg::query(0, m-1).mn == 0) return cout << 0 << endl, 0;
	for (auto& [l, r, p, q] : A) {
		auto qr = seg::query(l, r);
		int mn = qr.mn, mx = qr.mx;
		if (mn == 1 and mx != 1) return cout << 0 << endl, 0;
	}

	// dp[i]: probabilidade de preencher tudo ate aqui com uns;
	//      : de i eu transiciono pro inicio de todos os segmentos que terminam em i;

	vector<vector<int>> L(m+1);
	for (int i = 0; i < n; i++) {
		auto [l, r, p, q] = A[i];
		L[r+1].push_back(i);
	}

	vector<mint> dp(m+1, 0);
	dp[0] = 1;
	mint prob_ = 1;
	for (int i = 1; i <= m; i++) {
		for (int j : L[i]) {
			auto [l, r, p, q] = A[j];
			mint prob = p / mint(q);
			dp[i] += dp[l] * prob * (mint(1) / (mint(1) - prob));
			prob_ *= (mint(1) - prob);
		}
	}
	cout << dp[m] * prob_ << endl;

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
