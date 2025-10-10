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

struct Bit {
	int n;
	vector<double> F;
	Bit(int n_) : n(n_), F(n_ + 1, 0.0) {};
	void update(int i, double x) {
		for (++i; i <= n; i+=i&-i) F[i] += x;
	}
	double pref(int i) {
		double res = 0.0;
		for (++i; i; i-=i&-i) res += F[i];
		return res;
	}
	double query(int l, int r) {
		return pref(r) - pref(l-1);
	}
};

int solve() {
	int n; cin >> n;

	vector<vector<int>> G(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int t = 0;
	vector<int> L(n), R(n);
	function<void(int, int)> dfs = [&](int u, int p) {
		L[u] = t++;
		for (int v : G[u]) if (v != p) {
			dfs(v, u);	
		}
		R[u] = t-1;
	};
	dfs(0, -1);

	Bit bit(n);
	vector<double> B(n, 0.0);

	int q; cin >> q;
	while (q--) {
		int tp; cin >> tp;

		if (tp == 1) {
			int x, y; cin >> x >> y; x--;
			
			double y_ = logl(y);
			bit.update(L[x], y_ - B[x]);
			B[x] = y_;
		} else {
			int x, y; cin >> x >> y; x--, y--;
			double res = bit.query(L[x], R[x]) - bit.query(L[y], R[y]);

			if (res >= logl(1e9)) cout << "1000000000" << endl;
			else cout << fixed << setprecision(12) << exp(res) << endl;
		}
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
