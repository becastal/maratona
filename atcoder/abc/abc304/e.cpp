#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

struct Dsu {
	int n;
	vector<int> sz, id;
	Dsu(int n_) : n(n_), sz(n_, 1), id(n_) {
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
};

int solve() {
	int n, m; cin >> n >> m;

	Dsu dsu(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		dsu.merge(u, v);
	}

	set<array<int, 2>> R;
	int k; cin >> k;
	for (int i = 0, u, v; i < k; i++) {
		cin >> u >> v; u--, v--;
		u = dsu.find(u), v = dsu.find(v);
		if (u > v) swap(u, v);
		R.insert({u, v});
	}

	int q; cin >> q;
	for (int i = 0, u, v; i < q; i++) {
		cin >> u >> v; u--, v--;
		u = dsu.find(u), v = dsu.find(v);
		if (u > v) swap(u, v);
		cout << (R.count({u, v}) ? "No" : "Yes") << endl;
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

