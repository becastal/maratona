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
// da pra fazer so com hld e segtree normal
// mas vou fazer com: euler tour, lca com kth parent e fenwick tree pra me desafiar a implementar isso tudo.

struct Bit {
	int n;
	vector<int> bit;
	Bit(int _n=0) : n(_n), bit(n + 1) {}
	void update(int i, int x) {
		for (i++; i <= n; i += i & -i) bit[i] ^= x;
	}
	int pref(int i) {
		int ret = 0;
		for (i++; i; i -= i & -i) ret ^= bit[i];
		return ret;
	}
};

int solve() {
	int n, q; cin >> n >> q;
	int m = __lg(n) + 1;
	vector<int> A(n);
	vector<vector<int>> pai(n, vector<int>(m, 0)), G(n);

	for (int& i : A) cin >> i;
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int t = 0;
	vector<int> L(n), R(n), B(A), D(n, 0);
	function<void(int, int)> dfs = [&](int u, int p) {
		L[u] = t++;
		for (int v : G[u]) if (v != p) {
			B[v] ^= B[u];
			D[v] = D[u] + 1;
			dfs(v, pai[v][0] = u);
		}
		R[u] = t-1;
	};
	dfs(0, -1);

	for (int j = 1; j < m; j++) {
		for (int i = 0; i < n; i++) {
			pai[i][j] = pai[pai[i][j-1]][j-1];
		}
	}

	auto kth = [&](int u, int k) {
		for (int i = 0; i < m and u; i++) {
			if (k & (1 << i)) {
				u = pai[u][i];
			}
		}
		return u;
	};

	auto lca = [&](int a, int b) {
		if (D[b] > D[a]) swap(a, b);

		a = kth(a, D[a] - D[b]);	
		if (a == b) return a;

		for (int i = m-1; i >= 0; i--) {
			if (pai[a][i] != pai[b][i]) {
				a = pai[a][i];
				b = pai[b][i];
			}
		}

		return pai[a][0];
	};

	Bit bit(n);

	while (q--) {
		int tp; cin >> tp;

		if (tp == 1) {
			int u, x; cin >> u >> x; u--;
			bit.update(L[u], A[u] ^ x);
			if (R[u] + 1 < n) bit.update(R[u]+1, A[u] ^ x);
			A[u] = x;
		} else {
			int u, v; cin >> u >> v; u--, v--;
			cout << (B[u] ^ bit.pref(L[u]) ^ B[v] ^ bit.pref(L[v]) ^ A[lca(u, v)]) << endl;
		}
	};

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main() {
    _;
	setIO("cowland");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}
