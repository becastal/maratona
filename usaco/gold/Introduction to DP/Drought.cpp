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
typedef mod_int<(int)1e9+7> mint;


int solve() {
	int n, m = 1010, mn = m; cin >> n;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
		mn = min(mn, i);
	}

	auto calc = [&](int p) {
		vector<mint> dp(m+1, 1), dif(m+2, 0);

		for (int i = 1; i < n; i++) {
			int j = 0;
			while (j <= (A[i-1] - p) and A[i] - p - j + 1 >= 0) {
				int r = A[i] - p - j + 1;

				dif[0] += dp[j];
				dif[r] -= dp[j];
				j++;
			}

			dp[0] = dif[0];
			for (int j = 1; j <= m; j++) {
				dp[j] = dp[j-1] + dif[j];
			}
			fill(all(dif), mint(0));
		}

		return dp[0];
	};

	if (n & 1) {
		mint res = 0;
		for (int i = 0; i <= mn; i++) {
			res += calc(i);
		}
		cout << res << endl;
	} else {
		cout << calc(0) << endl;
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

