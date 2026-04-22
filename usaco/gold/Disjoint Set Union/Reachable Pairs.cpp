#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

struct Dsu {
	int n, res;
	vector<int> id, sz, cont;

	Dsu(int n_) : n(n_), res(0), id(n), sz(n, 1), cont(n, 0) {
		iota(all(id), 0);
	}

	int find(int u) {
		return (u == id[u] ? u : id[u] = find(id[u]));
	}

	int pares(int u) {
		return u * (u - 1) / 2;
	}

	int merge(int u, int v) {
		if ((u = find(u)) == (v = find(v))) return 0;
		if (sz[u] < sz[v]) swap(u, v);
		sz[u] += sz[v];
		id[v] = u;
		res -= pares(cont[u]), res -= pares(cont[v]);
		res += pares(cont[u] += cont[v]);
		return 1;
	}

	void liga(int u) {
		u = find(u);
		res -= pares(cont[u]);
		res += pares(++cont[u]);
	}
};

int solve() {
	int n, m; cin >> n >> m;
	string S; cin >> S;
	
	vector<vector<int>> G(n);
	vector<array<int, 2>> E(m);

	for (int i = 0; i < m; i++) {
		auto& [u, v] = E[i]; cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	Dsu dsu(n);
	vector<int> Res(n), Vivo(n);
	for (int i = 0; i < n; i++) if (S[i] == '1') {
		Vivo[i] = 1;
	}

	for (auto [u, v] : E) if (Vivo[u] and Vivo[v]) {
		dsu.merge(u, v);
	}

	for (int u = n-1; u >= 0; u--) {
		if (S[u] == '0') {
			Vivo[u] = 1;
			for (int v : G[u]) if (Vivo[v]) {
				dsu.merge(u, v);
			}
		}

		dsu.liga(u);
		Res[u] = dsu.res;
	}
	for (int i : Res) {
		cout << i << endl;
	}

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

