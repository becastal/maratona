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
typedef mod_int<(int)1e9+7> mint;

const int MAX = 2e5+10;
int divi[MAX];
void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;
}

void fact(map<int, int>& v, int n) {
	if (n != divi[n]) fact(v, n/divi[n]);
	v[divi[n]]++;
}

map<int, int> Fact(int x) {
	map<int, int> f;
	fact(f, x);
	return f;
}

int solve() {
	int n, q; cin >> n >> q;
	vector<int> A(n);

	// pra cada primo, eu so preciso saber qual o menor espoente que ele aparece
	vector<map<int, int>> B(n);
	map<int, map<int, int>> F;
	map<int, int> C;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		B[i] = Fact(A[i]);
		for (auto [p, e] : B[i]) {
			F[p][e]++;
			C[p]++;
		}
	}

	mint res = 1;
	for (auto [p, M] : F) if (C[p] == n) {
		res *= mint(p) ^ (M.begin()->f);
	}

	while (q--) {
		int i, x; cin >> i >> x; i--;
		for (auto [p, e] : Fact(x)) {
			int mn_antes = C[p] == n ? F[p].begin()->f : 0;

			if (B[i].count(p)) if (--F[p][B[i][p]] == 0) F[p].erase(B[i][p]);

			if (!B[i].count(p)) C[p]++;
			F[p][B[i][p] += e]++;
			int mn_depois = C[p] == n ? F[p].begin()->f : 0;

			if (mn_antes != mn_depois) res *= mint(p) ^ (mn_depois - mn_antes);
		}
		cout << res << endl;
	}

	return(0);
}

int main()
{
    _;

	crivo(MAX-1);
	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
