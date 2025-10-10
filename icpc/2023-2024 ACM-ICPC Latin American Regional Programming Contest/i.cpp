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
	mod_int(): v(0) {}
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
	friend m operator +(m a, m b) { return a += b; };
	friend m operator -(m a, m b) { return a -= b; };
	friend m operator *(m a, m b) { return a *= b; };
	friend m operator /(m a, m b) { return a /= b; };
};
typedef mod_int<(int)1e9+7> mint;

int solve() {
	string S; cin >> S;
	int n = (int)S.size();

	ll m_; cin >> m_;
	mint m = m_;
	vector<int> cont(26, 0), pal(26, 0);
	for (char c : S) pal[c - 'a']++;

	mint res = 0, c = (m * (m - 1) / 2);
	for (int i = n-1; i >= 0; i--) {

		mint x = 0, h = 0;
		for (int j = 0; j < S[i] - 'a'; j++) {
			x += cont[j];
			h += pal[j];
		}
		//cout << S[i] << ": " << x.v << ", " << h.v << endl;

		res += mint(m) * x + h * c;
		cont[S[i]-'a']++;
	}
	cout << res.v << endl;

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

