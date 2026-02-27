#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

/*
	nlog^2 com hash atualizando com Bit (acho que o log 
	da Bit talvez seja desnecessario)
*/

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
const int MOD = 1e9+9;
typedef mod_int<(int)1e9+9> mint;

struct Bit {
	int n;
	vector<mint> bit;
	Bit(int _n=0) : n(_n), bit(n + 1) {}
	Bit(vector<int>& v) : n(v.size()), bit(n + 1) {
		for (int i = 1; i <= n; i++) {
			bit[i] += v[i - 1];
			int j = i + (i & -i);
			if (j <= n) bit[j] += bit[i];
		}
	}
	void update(int i, mint x) {
		for (i++; i <= n; i += i & -i) bit[i] += x;
	}
	mint pref(int i) {
		mint ret = 0;
		for (i++; i; i -= i & -i) ret += bit[i];
		return ret;
	}
};

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
int p = uniform(256, MOD-1);

int solve() {
	int n; cin >> n;
	string A, B; cin >> A >> B;

	int pos = 0;
	for (; pos < n and A[pos] == B[pos]; pos++);
	if (pos == n) return cout << n << endl, 0;
	int res = pos;

	vector<mint> P(n + 1, 1), Hb(n + 1);
	for (int i = 1; i <= n; i++) {
		P[i] = P[i-1] * p;
		Hb[i] = Hb[i - 1] + P[i-1] * B[i-1];
	}

	Bit bit(n);
	for (int i = 0; i < n; i++) {
		bit.update(i, P[i] * A[i]);
	}

	auto swapH = [&](int a, int b) {

		bit.update(a, -(P[a] * A[a]));	
		bit.update(b, -(P[b] * A[b]));	
		swap(A[a], A[b]);
		bit.update(a, P[a] * A[a]);	
		bit.update(b, P[b] * A[b]);	
	};

	auto lcp = [&]() {
		int l = 0, r = n-1, ret = 0;

		while (l <= r) {
			int mid = l + (r - l) / 2;

			if (bit.pref(mid) != Hb[mid + 1]) {
				r = mid - 1;
			} else {
				l = mid + 1;
				ret = mid + 1;
			}
		}

		return ret;
	};

	for (int i = pos + 1; i < n; i++) {
		swapH(pos, i);	
		res = max(res, lcp());
		swapH(pos, i);	
	}
	cout << res << endl;

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

