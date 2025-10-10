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
	vector<ll> f;

	Bit(int n_) : n(n_), f(n_+1, 0) {};
	void update(int i, int x) {
		for (++i; i <= n; i += i & -i) f[i] += x;
	}
	ll pref(int i) {
		ll res = 0;
		for (++i; i; i -= i & -i) res += f[i];
		return res;
	}
};

int solve() {
	int n, q; cin >> n >> q;
	vector<int> T(n);

	map<int, vector<int>> M;
	map<int, vector<array<int, 3>>> Q;
	vector<vector<int>> G(n);

	for (int i = 0; i < n; i++) {
		cin >> T[i];
		M[T[i]].push_back(i);
	}

	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	for (int i = 0, a, b, ti; i < q; i++) {
		cin >> a >> b >> ti; a--, b--;
		Q[ti].push_back({a, b, i});
	}

	int t = 0, m = __lg(n) + 1;
	vector<vector<int>> pai(n, vector<int>(m, 0));
	vector<int> L(n), R(n), D(n, 0);
	function<void(int, int)> dfs = [&](int u, int p) {
		L[u] = t++;
		for (int v : G[u]) if (v != p) {
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
		for (int i = 0; i < m; i++) if (k >> i & 1) {
			u = pai[u][i];
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
	int ult = -1;
	vector<int> res(q);
	for (auto [ti, V] : Q) {
		if (ult != -1) {
			for (int u : M[ult]) {
				bit.update(L[u], -1);				
				if (R[u] + 1 < n) bit.update(R[u]+1, +1);				
			}
		}

		for (int u : M[ti]) {
			bit.update(L[u], +1);
			if (R[u] + 1 < n) bit.update(R[u]+1, -1);
		}

		for (auto [u, v, id] : V) {
			int w = lca(u, v);
			int cont = bit.pref(L[u]) + bit.pref(L[v]) - 2 * bit.pref(L[w]);
			int contw = bit.pref(L[w]) - (L[w] ? bit.pref(L[pai[w][0]]) : 0);
			res[id] = cont > 0 or contw > 0;
		}

		ult = ti;
	}

	for (int i : res) cout << i;
	cout << endl;

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main() {
    _;
	setIO("milkvisits");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}

