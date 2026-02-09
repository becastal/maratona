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
		v -= a.v; if (v < 0) v += p;
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

const int MAX = 1e6+10;
vector<mint> fat(MAX);

int solve() {
	string S; cin >> S;
	int n = (int)S.size();

	vector<vector<int>> Cs(n, vector<int>(10, 0));
	for (int i = n-1; i >= 0; i--) {
		if (i != n-1) Cs[i] = Cs[i+1];
		Cs[i][S[i]-'0']++;
	}

	auto esc = [&](int a, int b) -> mint {
		if (a < b or a < 0 or b < 0) return 0;
		return fat[a] / (fat[b] * fat[a-b]);
	};

	mint res = 0;
	vector<int> Cp(10, 0);
	for (int i = 0; i < n; i++) {
		if (S[i] == '0') {
			Cp[0]++;
			continue;
		}

		int d = S[i] - '0', ca = Cp[d-1], cb = Cs[i][d];
		if (ca >= 1) {
			res += esc(ca + cb - 1, ca - 1);
		}
		Cp[d]++
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	fat[0] = 1;
	for (int i = 1; i < MAX; i++) {
		fat[i] = fat[i-1] * i;
	}

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

