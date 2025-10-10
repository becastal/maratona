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
typedef mod_int<(int)1e9+9> mint1;
typedef mod_int<(int)1e9+7> mint2;

const int MAX = 4e5+10;
const ll pol = 2983472;
int F[MAX], FF[MAX];

int solve() {
	int n, k; cin >> n >> k;
	memset(F, 0, sizeof(F));
	memset(FF, 0, sizeof(FF));
	FF[0] = k;	

	vector<int> A(n);
	for (int& i : A) cin >> i, i--;

	vector<mint1> base1(k, 1);
	vector<mint2> base2(k, 1);
	for (int i = 1; i < k; i++) {
		base1[i] = base1[i-1] * pol;
		base2[i] = base2[i-1] * pol;
	}

	mint1 tudo1 = 0;
	mint2 tudo2 = 0;
	for (int i = 0; i < k; i++) {
		tudo1 += base1[i];
		tudo2 += base2[i];
	}

	int menor = 0, res = 0;
	mint1 agr1 = 0;
	mint2 agr2 = 0;
	map<pair<int, int>, int> M; M[{0, 0}] = -1;
	for (int i = 0; i < n; i++) {
		agr1 += base1[A[i]];
		agr2 += base2[A[i]];

		if (--FF[F[A[i]]] == 0 and F[A[i]] == menor) {
			menor++;
			agr1 -= tudo1;
			agr2 -= tudo2;
		}
		++FF[++F[A[i]]];

		pair<int, int> agr(agr1.v, agr2.v);
		if (!M.count(agr)) M[agr] = i;
		else {
			res = max(res, i - M[agr]);
		}
	}
	cout << res << endl;

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

