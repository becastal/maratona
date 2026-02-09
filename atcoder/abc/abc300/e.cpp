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
typedef mod_int<998244353> mint;

int solve() {
	ll n; cin >> n;
	int a = 0, b = 0, c = 0;

	while (n % 2 == 0) a++, n /= 2;
	while (n % 3 == 0) b++, n /= 3;
	while (n % 5 == 0) c++, n /= 5;

	if (n != 1) return cout << 0 << endl, 0;
	//cout << "a: " << a << ", b: " << b << ", c: " << c << endl;

	vector vis(a+1, vector(b+1, vector<int>(c+1, 0)));
	vector dp(a+1, vector(b+1, vector<mint>(c+1, 0)));
	dp[a][b][c] = 1;

	function<mint(int, int, int)> f = [&](int i, int j, int k) -> mint {
		if (i == a and j == b and k == c) return 1;
		if (i > a or j > b or k > c) return 0;
		if (vis[i][j][k]) return dp[i][j][k];
		vis[i][j][k] = 1;

		auto& agr = dp[i][j][k];
		agr += f(i+1, j, k); // 2;
		agr += f(i, j+1, k); // 3;
		agr += f(i+2, j, k); // 4;
		agr += f(i, j, k+1); // 5;
		agr += f(i+1, j+1, k); // 6;

		return agr /= mint(5);
	};

	cout << f(0, 0, 0) << endl;

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

