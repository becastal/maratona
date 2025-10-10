#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

template<int p> struct mod_int {
	ll expo(ll b, ll e) {
		ll ret = 1;
		while (e) {
			if (e % 2) ret = ret * b % p;
			e /= 2, b = b * b % p;
		}
		return ret;
	}
	ll inv(ll b) { return expo(b, p-2); };

	using m = mod_int;
	ll v;
	mod_int() : v(0) {};
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
	m& operator *=(const m& a) {
		v = v * ll(a.v) % p;
		return *this;
	}
	m& operator /=(const m& a) {
		v = v * ll(inv(a.v)) % p;
		return *this;
	}
	m& operator ^=(ll e) {
		v = expo(v, e);
		return *this;
	}
	friend m operator +(m a, m b) {
		return a += b;	
	}
	friend m operator *(m a, m b) {
		return a *= b;
	}
	friend m operator /(m a, m b) {
		return a /= b;
	}
	friend m operator ^(m a, ll b) {
		return a ^= b;
	}
};
typedef mod_int<(int)1e9+7> mint;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int n, m; cin >> n >> m;
	vector<int> A(m);
	for (int& i : A) cin >> i;
	A.insert(A.begin(), 1);
	m++;

	vector<mint> suf(m);
	for (int i = m; i >= 0; i--) {
		suf[i] = i + 1 < m ? suf[i + 1] : mint(0);
		suf[i] += A[i] / (mint(2) ^ (i + 2));
	}

	vector<mint> R(n);
	for (int i = 0; i < m; i++) {
		int add = (!i and A[i] == 1);
		if (i + 1 < m) R[A[i]-1] += suf[i + 1] * (mint(2) ^ (i + 1 + add));
	}

	for (int i = 0; i < n; i++) {
		cout << R[i].v << endl;
	}
	
	return 0;
}
