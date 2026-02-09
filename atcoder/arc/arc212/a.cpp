#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
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

const int MAX = 5050;
mint fat[MAX];

mint C(int n, int k) {
	if (n < k or n < 0 or k < 0) return mint(0);
	return fat[n] / (fat[n - k] * fat[k]);	
}

mint stars(int n, int k) {
	return C(n + k - 1, n);
}

int solve() {
	int k; cin >> k;

	mint res = 0;
    for (int U = 2; U <= k - 4; ++U) {
        for (int V = 2; V <= k - U - 2; ++V) {
            int W = k - U - V;
            if (W < 2) continue;

            int mx = max({U, V, W});
            res += mint(U - 1) * mint(V - 1) * mint(W - 1) * mint(k - mx);
        }
    }
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	fat[0] = fat[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fat[i] = fat[i-1] * i;
	}

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

