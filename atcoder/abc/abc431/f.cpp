#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*

quantas permutacoes existem tal que A[i] >= A[i-1] - d;

pra todo valor eu consigo dizer quantos tem que ir na 
minha frente (quantos que A[i] < A[j] - d);

basta ordenar e dai eh two pointers.

dai eh contar quantidade de ordenacoes topologicas?
se (A[i] < A[j] - d, entao faz aresta i -> j).
mesmo se for eu nao so nao sei como faze mas tambem
nao posso construir o grafo.

ideia promissora.
contar ordenacoes topologicas nao da em tempo polinomial
entao talvez tenha uma manha mais esperta de como conta-las
particularmente, depois de ordenar um A

*/

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
const int mod = 998244353;
const int MAX = 3e5+10;

int solve() {
	int n, d; cin >> n >> d;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	int mx = *max_element(all(A));
	vector<int> F(mx+1);
	for (int i : A) {
		F[i]++;
	}

    vector<mint> fat(MAX+1, 1), invfat(MAX+1, 1);
    for (int i = 1; i <= MAX; i++) {
        fat[i] = fat[i - 1] * i;
    }

    invfat[MAX] = fat[MAX] ^ (mod - 2);
    for (ll i = MAX; i > 0; i--) {
        invfat[i - 1] = invfat[i] * i;
    }

	auto C = [&fat, &invfat](int a, int b) {
		if (a < 0 or b < 0 or b > a) return mint(0);
		return (fat[a] * invfat[b] * invfat[a - b]);
	};

	mint res = 1;
	for (int i = 0, s = 0; i <= mx; i++) {
		s += F[i];
		res *= C(s, F[i]);
		if (i - d >= 0) s -= F[i-d];
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

