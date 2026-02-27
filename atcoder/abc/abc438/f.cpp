#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n; cin >> n;
	int LOG = __lg(n) + 2;

	vector<vector<int>> G(n), Pai(n, vector<int>(LOG + 1));
	vector<int> Sub(n), D(n);

	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	function<int(int, int)> dfs = [&](int u, int p) { 
		Sub[u] = 1;
		for (int v : G[u]) if (v != p) {
			D[v] = D[u] + 1;
			Sub[u] += dfs(v, Pai[v][0] = u);	
		}
		return Sub[u];
	};
	dfs(0, -1);

	for (int i = 1; i <= LOG; i++) {
		for (int j = 0; j < n; j++) {
			Pai[j][i] = Pai[Pai[j][i-1]][i-1];
		}
	}

	function<int(int, int)> kth = [&](int u, int k) {
		for (int i = LOG; i >= 0; i--) if (k >> i & 1) {
			u = Pai[u][i];
		}
		return u;
	};

	function<int(int, int)> lca = [&](int u, int v) { 
		if (D[u] > D[v]) swap(u, v);
		v = kth(v, D[v] - D[u]);
		if (u == v) return u;

		for (int i = LOG; i >= 0; i--) if (Pai[u][i] != Pai[v][i]) {
			u = Pai[u][i];
			v = Pai[v][i];
		}
		return Pai[u][0];
	};

	function<int(int, int)> dis = [&](int u, int v) {
		return D[u] + D[v] - 2 * D[lca(u, v)];
	};

	function<int(int, int, int)> dentro = [&](int a, int u, int v) {
		return dis(u, a) + dis(a, v) == dis(u, v);
	};

	function<int(int, int)> vizinho = [&](int u, int v) {
		int c = lca(u, v);
		if (c != u) return Pai[u][0];
		else {
			int d = D[v] - D[u] - 1;
			return kth(v, d);
		}
	};

	function<int(int, int)> tam = [&](int u, int u_) {
		if (Pai[u][0] == u) {
			return n - Sub[u_];
		} else {
			return Sub[u];
		}
	};

	int res = n * (n + 1) / 2;
	for (int v : G[0]) {
		res -= Sub[v] * (Sub[v] + 1) / 2;	
	}

	int a = 0, b = 0;
	for (int u = 1; u < n; u++) {
		if (dentro(u, a, b)) {

		} else if (dentro(b, a, u)) {
			b = u;
		} else if (dentro(a, b, u)) {
			a = u;
		} else break;

		int a_ = vizinho(a, b);
		int b_ = vizinho(b, a);
		res += tam(a, a_) * tam(b, b_);
	}
	cout << res << endl;

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

