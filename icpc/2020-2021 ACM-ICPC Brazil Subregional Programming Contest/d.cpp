#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

template<typename T> vector<int> pi(T s) {
	vector<int> p(s.size());
	for (int i = 1, j = 0; i < s.size(); i++) {
		while (j and s[j] != s[i]) j = p[j-1];
		if (s[j] == s[i]) j++;
		p[i] = j;
	}
	return p;
}

template<typename T> vector<int> matching(T& s, T& t) {
	vector<int> p = pi(s), match;
	for (int i = 0, j = 0; i < t.size(); i++) {
		while (j and s[j] != t[i]) j = p[j-1];
		if (s[j] == t[i]) j++;
		if (j == s.size()) match.push_back(i-j+1), j = p[j-1];
	}
	return match;
}

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
typedef mod_int<(int)1e9+7> mint;

const int MAX = 1e6+10;
mint fact[MAX];

mint choose(int n, int k) {
	if (k > n) return mint(0);
	return fact[n] / (fact[n - k] * fact[k]);
}

int solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> A(n), B(n);
	for (int& i : A) {
		cin >> i;
		i %= m;
	}
	for (int& i : B) {
		cin >> i;
		i %= m;
	}

	vector<int> A_ = A;
	for (int i : A) {
		A_.push_back(i);
	}

	vector<int> DA_(2 * n - 2), DB(n - 1);
	for (int i = 1; i < 2 * n - 1; i++) {
		DA_[i-1] = A_[i] - A_[i-1];
	}
	for (int i = 1; i < n; i++) {
		DB[i-1] = B[i] - B[i-1];
		DB[i-1] *= -1;
	}

	vector<int> Pos = matching(DB, DA_);

	mint res = 0;
	for (int p : Pos) {
		mint add = choose(n - 1 - (!!p), k - 1) * fact[k - 1];	
		cout << "p: " << p << " = " << "C(" << n - 1 - (!!p) << ", " << k - 1 << ") = \n" << choose(n - 1 - (!!p), k - 1) << "\n";
		res += choose(n - 1 - (!!p), k - 1) * fact[k - 1];	
	}
	cout << res << endl;

	return(0);
}

signed main()
{
    _;

	fact[0] = 1;
	for (int i = 1; i < MAX; i++) {
		fact[i] = fact[i-1] * i;
	}

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

