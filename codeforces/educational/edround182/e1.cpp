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
	int n; cin >> n;
	vector<int> H(n);
	for (int& i : H) cin >> i;

	vector<int> L(n), R(n);
	stack<int> S;
	
	for (int i = 0; i < n; i++) {
		while (S.size() and H[S.top()] <= H[i]) S.pop();
		L[i] = S.size() ? S.top() : -1;
		S.push(i);
	}

	while (S.size()) S.pop();
	for (int i = n-1; i >= 0; i--) {
		while (S.size() and H[S.top()] <= H[i]) S.pop();
		R[i] = S.size() ? S.top() : n;
		S.push(i);
	}

	vector<int> A, B;
	for (int u = 0; u < n; u = R[u]) {
		A.push_back(H[u]);
	}
	for (int u = n-1; u >= 0; u = L[u]) {
		B.push_back(H[u]);
	}
	B.pop_back();
	//for (int i : A) cout << i << ' '; cout << endl;
	//for (int i : B) cout << i << ' '; cout << endl;

	auto calc = [&H, n](vector<int>& A) {
		int m = (int)A.size();
		vector<mint> dp(n + 1, 1);
		
		for (int j = 1; j <= m; j++) {
			vector<mint> dp_(n + 1, 0);	

			for (int i = 1; i <= n; i++) {
				dp_[i] += dp_[i-1];

				if (H[i-1] == A[j-1]) {
					dp_[i] += dp[i-1];
				}
				if (H[i-1] <= A[j-1]) {
					dp_[i] += dp_[i-1];
				}
			}

			dp.swap(dp_);
		}

		return dp;
	};

	vector<mint> dpA = calc(A);
	reverse(all(H));
	vector<mint> dpB = calc(B);
	reverse(all(H));

	mint res = 0;
	int mx = *max_element(all(H));
	for (int i = 0; i < n; i++) if (H[i] == mx) {
		mint l = dpA[i+1] - dpA[i];	
		mint r = dpB[n-i];
		res += l * r;
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

