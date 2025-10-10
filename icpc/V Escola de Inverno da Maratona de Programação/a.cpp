#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

struct matrix {
	int n;
	vector<bitset<500>> a;

	matrix(int n_) : n(n_), a(n_) {}

	matrix operator*(matrix r) {
		assert(n == r.n);
		matrix res(n);

		vector<bitset<500>> r_(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (r.a[i][j]) r_[j][i] = 1;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ((a[i] & r_[j]).any()) {
					res.a[i].set(j);
				}
			}
		}

		return res;
	};
	
	matrix operator^(ll e){
		matrix M(n), at = *this;
		for (int i = 0; i < n; i++) {
			M.a[i][i] = 1;
		}
		while (e) {
			if (e&1) M = M*at;
			e >>= 1;
			at = at*at;
		}
		return M;
	}
};

int solve() {
	int n, m; cin >> n >> m;
	matrix M(n);

	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		M.a[u][v] = 1;	
	}

	int k; cin >> k;
	M = M ^ k;

	vector<int> vis(n, 0);
	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;

		for (int v = 0; v < n; v++) {
			if (!vis[v] and M.a[u][v]) {
				dfs(v);
			}
		}
	};

	dfs(0);
	cout << (vis[n-1] ? "Sim" : "Nao") << endl;

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
