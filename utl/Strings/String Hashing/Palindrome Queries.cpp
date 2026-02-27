#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

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

typedef mod_int<(int)1e9+9> mint;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

const int MOD = 1e9+9;
int p = uniform(6969, MOD-1);

struct Bit {
	int n;
	vector<mint> F;

	Bit(int n_) : n(n_), F(n+1) {}
	void update(int i, mint x) {
		for (i++; i <= n; i += i&-i) {
			F[i] += x;
		}
	}

	mint pref(int i) {
		mint res = 0;
		for (i++; i; i -= i&-i) {
			res += F[i];
		}
		return res;
	}

	mint query(int l, int r) {
		return pref(r) - pref(l);
	}
};

int solve() {
	int n, q; cin >> n >> q;
	string S; cin >> S;

	vector<mint> Base(n + 1, 1);
	for (int i = 1; i <= n; i++) {
		Base[i] = Base[i-1] * p;
	}

	Bit bit(n), bit_(n);

	for (int i = 0; i < n; i++) {
		bit.update(i, Base[i] * S[i]);
		bit_.update(i, Base[i] * S[n-1-i]);
	}

	auto pal = [&](int l, int r) {
		int l_ = n - 1 - r, r_ = n - 1 - l;	
		mint a = bit.query(l, r), b = bit_.query(l_, r_);
		a /= Base[l], b /= Base[l_];
		return a == b;
	};

    while (q--) {
        int tp; cin >> tp;

        if (tp == 1) {
            int i; char a;
            cin >> i >> a; i--;

            int j = n - 1 - i;

            bit.update(i,  -(Base[i] * S[i]));
            bit_.update(j, -(Base[j] * S[i]));

            S[i] = a;

            bit.update(i,  Base[i] * S[i]);
            bit_.update(j, Base[j] * S[i]);
        } else {
            int l, r; cin >> l >> r; l--, r--;
            cout << (pal(l, r) ? "YES" : "NO") << '\n';
        }
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

