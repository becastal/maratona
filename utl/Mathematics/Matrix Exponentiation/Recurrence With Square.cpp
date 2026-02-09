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
typedef mod_int<(int)1e9+7> mint;

template <typename T>
struct Mat {
	int n;
	vector<vector<T>> A;

	Mat(int n_, int id = 0) : n(n_), A(n, vector<T>(n, 0)) {
		if (id) for (int i = 0; i < n; i++) {
			A[i][i] = 1;
		}
	}

	Mat operator * (const Mat& M) {
		Mat R(n);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					R.A[i][j] += A[i][k] * M.A[k][j];
				}
			}
		}

		return R;
	}

	Mat& operator *= (const Mat& M) {
		return *this = (*this) * M;
	}

	Mat operator ^ (int k) {
		Mat B(n, 1), base = (*this);

		while (k) {
			if (k & 1) B *= base;
			base *= base;
			k >>= 1;
		}

		return B;
	}

	Mat& operator ^= (int k) {
		return *this = (*this) ^ k;
	}
};


int solve() {
	int n; ll k;
	cin >> n >> k;

	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	Mat M(n);
	for (int i = 0; i < n - 1; i++) {
		M.A[i][i + 1] = mint(1);
	}
	for (int i = 0; i < n; i++) {
		M.A[n-1][i] = mint(A[n - i - 1]);
	}




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

