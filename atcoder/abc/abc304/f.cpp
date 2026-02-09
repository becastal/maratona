#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
	pra cada divisor d de n:
		- algumas posicoes vao ter que ser #
		- todas as outras tanto faz
		- entao eh sempre pot de 2
		- pra cada m eh (1 << count(all()) pra quantos . tem em [0, ..., m-1])

	foda eh recontar as mesmas configs
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

vector<int> divisores(int n) {
	vector<int> D;
	for (int i = 1; i * i <= n; i++) if (n % i == 0) {
		D.push_back(i);		
		if (n / i != i and i != 1) D.push_back(n / i);
	}
	sort(all(D));
	return D;
}

int solve() {
	int n; cin >> n;
	string S; cin >> S;

	vector<int> D = divisores(n);
	int m = (int)D.size();

	vector<mint> R(m);
	for (int i = 0; i < m; i++) {
		int d = D[i];
		vector<int> C(d, 0);
		for (int j = 0; j < n; j++) if (S[j] == '.') {
			C[j % d] = 1;
		}
		int e = count(all(C), 0);
		R[i] = mint(2) ^ e;
	}

	mint res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < i; j++) {
            if (D[i] % D[j] == 0) {
                R[i] -= R[j];
            }
        }
        res += R[i];
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

