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

const int MAX = 2e5+10;
mint pot[MAX];

int solve() {
	int n; cin >> n;

	vector<vector<int>> G(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	G[0].push_back(-1);

	int dlca = -1;
	vector<int> A;
	function<void(int, int, int)> dfs = [&](int u, int p, int d) {
		if (G[u].size() > 2) dlca = d;

		int folha = 1;
		for (int v : G[u]) if (v != p) {
			dfs(v, u, d+1);
			folha = 0;
		};

		if (folha) A.push_back(d);
	};
	dfs(0, -1, 1);

	if (A.size() > 2) return cout << 0 << endl, 0;
	if (A.size() == 1) return cout << pot[n] << endl, 0;

	int dif = abs(A[0] - A[1]);
	if (dif) cout << pot[dif + dlca] + pot[dif + dlca - 1] << endl;
	else cout << 2 * pot[dif + dlca] << endl;

	return(0);
}

int main()
{
    _;

	pot[0] = 1;
	for (int i = 1; i < MAX; i++) pot[i] = pot[i-1] * 2;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
