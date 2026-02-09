#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
const ll LINF = 1e18+19;

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
const int mod = 1e6+3;
typedef mod_int<mod> mint;
vector<mint> fact(mod + 1, 1);

int solve() {
	int n; cin >> n;
	
	vector<int> A(n), B(n);

	for (int& i : A) cin >> i;
	for (int& i : B) cin >> i;

	auto f = [&](int a, int b, int k) -> ll {
		ll res = 0;
		while (b > a and k) {
			if (b & 1) {
				b--, res++;
			} else {
				if ((b >> 1) >= a) {
					b >>= 1;
					k--;
				} else break;
			}
		}

		res += max(0, (b - a));
		if (k) return LINF;
		return res;
	};

	int ko = -1;
	ll res = LINF;
	for (int k = 0; k < 20; k++) {

		ll agr = k;
		for (int i = 0; i < n; i++) {
			ll s = f(A[i], B[i], k);	
			if (s == LINF) {
				agr = LINF;
				break;
			}
			agr += s;
		}

		if (res > agr) {
			res = agr;
			ko = k;
		}
	}

	vector<ll> cont(ko);
	vector<int> B_(B), C(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < ko; j++) {
			cont[j] += B_[i] & 1;
			B_[i] >>= 1;
		}
		C[i] = max(0, B_[i] - A[i]);
	}

	mint resb = 1;
	for (int j = 0; j < ko; j++) {
		resb *= fact[cont[j]];
	}

	ll sobra = accumulate(all(C), 0LL);
	if (sobra >= mod) resb = 0;
	else {
		resb *= fact[sobra];
	}

	for (int i = 0; i < n; i++) if (C[i]) {
		resb *= (mint(1) / fact[C[i]]);
	}

	cout << res << ' ' << resb << endl;

	return(0);
}

int main()
{
    _;
	
	for (int i = 2; i < mod; i++) {
		fact[i] = fact[i-1] * i;
	}
	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

