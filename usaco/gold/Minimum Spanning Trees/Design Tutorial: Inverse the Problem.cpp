#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

struct Dsu {
	int n;
	vector<int> id, sz;
	Dsu(int n_) : n(n_), id(n), sz(n, 1) {
		iota(all(id), 0);
	}
	int find(int u) {
		return u == id[u] ? u : id[u] = find(id[u]);
	}
	void merge(int u, int v) {
		if ((u = find(u)) == (v = find(v))) return;
		if (sz[v] > sz[u]) swap(u, v);
		sz[u] += sz[v];
		id[v] = u;
	}
};

int solve() {
	int n; cin >> n;
	vector<vector<int>> A(n, vector<int>(n));

	vector<array<int, 3>> E(n*n);
	for (int i = 0, p = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
			E[p++] = {A[i][j], i, j};
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) if (i != j) {
			if (A[i][j] != A[j][i] or A[i][j] <= 0) return cout << "NO" << endl, 0;
		}
	}

	vector<vector<array<int, 2>>> G(n);

	Dsu dsu(n);
	sort(all(E));
	for (auto [w, u, v] : E) if (dsu.find(u) != dsu.find(v)) {
		dsu.merge(u, v);
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}

	auto dfs = [&](int in) {
		vector<int> D(n);

		D[in] = 0;
		function<void(int, int)> f = [&](int u, int p) {
			for (auto [v, w] : G[u]) if (v != p) {
				D[v] = D[u] + w;
				f(v, u);
			}
		};
		f(in, -1);

		return D;
	};

	for (int i = 0; i < n; i++) {
		auto D = dfs(i);
		if (D != A[i]) return cout << "NO" << endl, 0;
	}
	cout << "YES" << endl;


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

