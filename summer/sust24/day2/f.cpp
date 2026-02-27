#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

struct Dsu {
	int n;
	vector<int> sz, id;
	Dsu (int n_) : n(n_), sz(n, 1), id(n) {
		iota(all(id), 0);
	}

	int find(int u) {
		return u == id[u] ? u : id[u] = find(id[u]);
	}

	int merge(int u, int v) {
		if ((u = find(u)) == (v = find(v))) return 0;
		if (sz[u] < sz[v]) swap(u, v);
		sz[u] += sz[v];
		id[v] = u;
		return 1;
	}

	int tam(int u, int v) {
		if ((u = find(u)) == (v = find(v))) return sz[u];
		return sz[u] + sz[v];
	}
};

int solve() {
	int n, m; cin >> n >> m;
	vector<array<int, 2>> E(m);
	for (auto& [u, v] : E) {
		cin >> u >> v; u--, v--;
	}

	int q; cin >> q;
	vector<array<int, 3>> Q(q);

	for (auto& [u, v, z] : Q) {
		cin >> u >> v >> z; u--, v--;
	}

	vector<array<int, 2>> Bounds(q, {0, m-1});
	vector<int> R(q);
	vector<vector<int>> Mids(m);

	for (int rep = 0, lim = __lg(m) + 2; rep < lim; rep++) {
		for (int i = 0; i < q; i++) {
			auto [l, r] = Bounds[i];

			if (l <= r) {
				int mid = l + (r - l) / 2;
				Mids[mid].push_back(i);
			}
		}

		Dsu dsu(n);
		for (int mid = 0; mid < m; mid++) {
			auto& [a, b] = E[mid];
			dsu.merge(a, b);	

			for (int i : Mids[mid]) {
				auto& [u, v, z] = Q[i];
				auto& [l, r] = Bounds[i];
				if (dsu.tam(u, v) >= z) {
					R[i] = mid;
					r = mid - 1;
				} else {
					l = mid + 1;	
				}
			}
			Mids[mid].clear();
		}
	}

	for (int i : R) {
		cout << i + 1 << endl;
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

