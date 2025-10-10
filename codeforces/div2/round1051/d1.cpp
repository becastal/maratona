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
typedef mod_int<(int)1e9+7> mint;

int bruta() {
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	map<pair<int, int>, int> M;

	for (int i : A) {
		map<pair<int, int>, int> M_;
		
		M_[{i, i}]++;
		M_[{i, INT_MAX}]++;
		M_[{INT_MAX, i}]++;

		for (auto [p, f] : M) {
			auto [a, b] = p;
			if (i < a and i < b) continue;
			
			M_[{a, b}] += M[{a, b}];
			//M_[{i, b}] += M[{a, b}];
			//M_[{a, i}] += M[{a, b}];
		}

		M.swap(M_);
		for (auto [p, b] : M) cout << p.first << ", " << p.second << ": " << b << endl;
		cout << endl;
	}

	return 0;
}

int solve() {
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	vector dp(n+1, vector<mint>(n+1, 0));
	dp[0][0] = 1;

	//for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) cout << dp[i][j] << " \n"[j==n]; cout << endl;
	for (int i = 0; i < n; i++) {
		vector dp_(n+1, vector<mint>(n+1, 0));

		for (int a = 0; a <= n; a++) {
			for (int b = a; b <= n; b++) {

				dp_[a][b] += dp[a][b];
				if (A[i] >= b) dp_[a][A[i]] += dp[a][b];
				else if (A[i] >= a) dp_[A[i]][b] += dp[a][b];
			}
		}

		dp.swap(dp_);
		//for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) cout << dp[i][j] << " \n"[j==n]; cout << endl;
	}

	mint res = 0;
	for (int a = 0; a <= n; a++) {
		for (int b = a; b <= n; b++) {
			res += dp[a][b];
		}
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

