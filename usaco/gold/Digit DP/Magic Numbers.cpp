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

struct bint {
	static const int BASE = 1e9;
	vector<int> v;
	bool neg;

	bint() : neg(0) {}
	bint(int val) : bint() { *this = val; }
	bint(long long val) : bint() { *this = val; }

	void trim() {
		while (v.size() and v.back() == 0) v.pop_back();
		if (!v.size()) neg = 0;
	}

	// converter de/para string | cin/cout
	bint(const char* s) : bint() { from_string(string(s)); }
	bint(const string& s) : bint() { from_string(s); }
	void from_string(const string& s) {
		v.clear(), neg = 0;
		int ini = 0;
		while (ini < s.size() and (s[ini] == '-' or s[ini] == '+' or s[ini] == '0'))
			if (s[ini++] == '-') neg = 1;
		for (int i = s.size()-1; i >= ini; i -= 9) {
			int at = 0;
			for (int j = max(ini, i - 8); j <= i; j++) at = 10*at + (s[j]-'0');
			v.push_back(at);
		}
		if (!v.size()) neg = 0;
	}
	string to_string() const {
		if (!v.size()) return "0";
		string ret;
		if (neg) ret += '-';
		for (int i = v.size()-1; i >= 0; i--) {
			string at = ::to_string(v[i]);
			int add = 9 - at.size();
			if (i+1 < v.size()) for (int j = 0; j < add; j++) ret += '0';
			ret += at;
		}
		return ret;
	}
	friend istream& operator>>(istream& in, bint& val) {
		string s; in >> s;
		val = s;
		return in;
	}
	friend ostream& operator<<(ostream& out, const bint& val) {
		string s = val.to_string();
		out << s;
		return out;
	}

	// operators
	friend bint abs(bint val) {
		val.neg = 0;
		return val;
	}
	friend bint operator-(bint val) {
		if (val != 0) val.neg ^= 1;
		return val;
	}
	bint& operator=(const bint& val) { v = val.v, neg = val.neg; return *this; }
	bint& operator=(long long val) {
		v.clear(), neg = 0;
		if (val < 0) neg = 1, val *= -1;
		for (; val; val /= BASE) v.push_back(val % BASE);
		return *this;
	}
	int cmp(const bint& r) const { // menor: -1 | igual: 0 | maior: 1
		if (neg != r.neg) return neg ? -1 : 1;
		if (v.size() != r.v.size()) {
			int ret = v.size() < r.v.size() ? -1 : 1;
			return neg ? -ret : ret;
		}
		for (int i = int(v.size())-1; i >= 0; i--) {
			if (v[i] != r.v[i]) {
				int ret = v[i] < r.v[i] ? -1 : 1;
				return neg ? -ret : ret;
			}
		}
		return 0;
	}
	friend bool operator<(const bint& l, const bint& r) { return l.cmp(r) == -1; }
	friend bool operator>(const bint& l, const bint& r) { return l.cmp(r) == 1; }
	friend bool operator<=(const bint& l, const bint& r) { return l.cmp(r) <= 0; }
	friend bool operator>=(const bint& l, const bint& r) { return l.cmp(r) >= 0; }
	friend bool operator==(const bint& l, const bint& r) { return l.cmp(r) == 0; }
	friend bool operator!=(const bint& l, const bint& r) { return l.cmp(r) != 0; }

	bint& operator +=(const bint& r) {
		if (!r.v.size()) return *this;
		if (neg != r.neg) return *this -= -r;
		for (int i = 0, c = 0; i < r.v.size() or c; i++) {
			if (i == v.size()) v.push_back(0);
			v[i] += c + (i < r.v.size() ? r.v[i] : 0);
			if ((c = v[i] >= BASE)) v[i] -= BASE;
		}
		return *this;
	}
	friend bint operator+(bint a, const bint& b) { return a += b; }
	bint& operator -=(const bint& r) {
		if (!r.v.size()) return *this;
		if (neg != r.neg) return *this += -r;
		if ((!neg and *this < r) or (neg and r < *this)) {
			*this = r - *this;
			neg ^= 1;
			return *this;
		}
		for (int i = 0, c = 0; i < r.v.size() or c; i++) {
			v[i] -= c + (i < r.v.size() ? r.v[i] : 0);
			if ((c = v[i] < 0)) v[i] += BASE;
		}
		trim();
		return *this;
	}
	friend bint operator-(bint a, const bint& b) { return a -= b; }
};

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
mint dp[2010][2][2][2][2010];
int vis[2010][2][2][2][2010];

int solve() {
	int m, d; cin >> m >> d;
	bint a, b; cin >> a >> b;
	a -= bint(1);
	string A = a.to_string(), B = b.to_string();
	while (A.size() < B.size()) A = "0" + A;

	int P[2010];
	P[0] = 1 % m;
	for (int i = 1; i < 2010; i++) {
		P[i] = (P[i-1] * 10) % m;
	}

	auto calc = [&](string& S) {
		int n = S.size();
		memset(vis, 0, sizeof(vis));

		auto f = [&](auto&& f, int pos, int tight, int zeroE, int par, int soma) -> mint {
			if (pos == n) return mint(soma == 0);
			if (vis[pos][tight][zeroE][par][soma]) return dp[pos][tight][zeroE][par][soma];
			vis[pos][tight][zeroE][par][soma] = 1;
			
			int teto = tight ? S[pos] - '0' : 9;
			mint res = 0;
			for (int i = 0; i <= teto; i++) {
				if (par) {
					if (i != d) continue;
				} else {
					if (i == d) continue;
				}
				res += f(f, 
						pos + 1, 
						tight and i == teto, 
						zeroE and i == 0, 
						(zeroE and i == 0) ? par : (par ^ 1),
						(soma + i * P[n-1-pos]) % m);
			}
			return dp[pos][tight][zeroE][par][soma] = res;
		};
		return f(f, 0, 1, 1, 0, 0);
	};
	cout << calc(B) - calc(A) << endl;;

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
