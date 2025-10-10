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
typedef mod_int<(int)1e9+9> mint;

int solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> A(n), B(m);
	for (int& i : A) cin >> i;
	for (int& i : B) cin >> i;
	sort(all(A));
	sort(all(B));

	vector dp(k+1, vector(n+1, vector<mint>(m+1, 0)));
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			dp[0][i][j] = 1;
		}
	}

	// dp[k][i][j]: quantas sequencias de tamanho k existem usando os
	// 				primeiros i valores de A e os primeiros j valores
	// 				de B;
	for (int kth = 1; kth <= k; kth++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[kth][i][j] += dp[kth][i-1][j] + dp[kth][i][j-1] - dp[kth][i-1][j-1];
				if (A[i-1] > B[j-1]) dp[kth][i][j] += dp[kth-1][i-1][j-1];
			}
		}
	}

	cout << dp[k][n][m] << endl;

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main() {
    _;
	setIO("team");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}

