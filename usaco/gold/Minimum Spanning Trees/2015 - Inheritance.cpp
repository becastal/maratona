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
	vector<int> id, sz;

	Dsu(int n_) : n(n_), id(n), sz(n, 1) {
		iota(all(id), 0);
	}

	int find(int u) {
		return id[u] == u ? u : id[u] = find(id[u]);
	}

	int merge(int u, int v) {
		if ((u = find(u)) == (v = find(v))) return 0;
		if (sz[u] < sz[v]) swap(u, v);
		sz[u] += sz[v];
		id[v] = u;
		return 1;
	}

	int mesmo(int u, int v) {
		return find(u) == find(v);
	}
};

int solve() {
	int n, m, k; cin >> n >> m >> k;

	vector<Dsu> dsu(k, Dsu(n));

	vector<array<int, 4>> E(m);
	for (int i = 0; i < m; i++) {
		auto& [w, u, v, id] = E[i];
		cin >> u >> v >> w; u--, v--;
		id = i;
	}
	sort(rall(E));

	vector<int> Res(m);
	for (auto [w, u, v, id] : E) {
		int l = 0, r = k-1, pos = -1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (!dsu[mid].mesmo(u, v)) {
				r = mid - 1;
				pos = mid;
			} else {
				l = mid + 1;
			}
		}
		
		if (pos != -1) {
			dsu[pos].merge(u, v);
		}
		Res[id] = pos + 1;
	}

	for (int i = 0; i < m; i++) { 
		cout << Res[i] << endl;
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

