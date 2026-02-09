#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

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

const int MAX = 1010;
mint dp[MAX][MAX][3][3];
int vis[MAX][MAX][3][3];

int solve() {
	int n; cin >> n;

	memset(vis, 0, sizeof(vis));
	function<mint(int, int, int, int)> calc = [&](int pos, int comps, int blk_borda, int blk_meio) {
		if (pos == n) return mint(comps == 1);

		mint& res = dp[pos][comps][blk_borda][blk_meio];
		if (vis[pos][comps][blk_borda][blk_meio]) return res;

		res = 0;

		// criando
		if (comps == 0) {
			res += calc(pos + 1, 1, 2, 0);
		}

		if (comps >= 1) {
			res += mint(2) * calc(pos + 1, comps + 1, 1, 1); // borda
		} 

		if (comps >= 2) {
			res += calc(pos + 1, comps + 1, 0, 2) * mint(comps - 1); // meio
		}

		if (comps >= 1) {
			res += calc(pos + 1, comps, 1, 0) * mint(2 - blk_borda);
		}

		if (comps >= 2) {
			res += mint(2 * (comps - 1) - blk_meio) * calc(pos + 1, comps, 0, 1);
		}

		if (comps >= 2) {
			res += mint(comps - 1 - blk_meio) * calc(pos + 1, comps - 1, 0, 0);
		}

		vis[pos][comps][blk_borda][blk_meio] = 1;
		return res;
	};
	cout << calc(0, 0, 0, 0) << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

