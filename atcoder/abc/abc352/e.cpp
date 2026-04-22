#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

struct Dsu {
	int n, cc;
	vector<int> id, sz;

	Dsu(int n_) : n(n_), cc(n), id(n), sz(n, 1) {
		iota(all(id), 0);
	}

	int find(int u) {
		return u == id[u] ? u : id[u] = find(id[u]);
	}

	int merge(int u, int v) {
		if ((u = find(u)) == (v = find(v))) return 0;
		if (sz[u] < sz[v]) swap(u, v);
		sz[u] += v;
		id[v] = u;
		cc--;
		return 1;
	}
};

int solve() {
	int n, m; cin >> n >> m;

	vector<pair<int, vector<int>>> E(m);
	for (int i = 0, k; i < m; i++) {
		auto& [c, V] = E[i];
		cin >> k >> c;

		V = vector<int>(k);
		for (int& u : V) {
			cin >> u; u--;
		}
	}

	Dsu dsu(n);
	sort(all(E));
	int res = 0;
	for (auto [w, V] : E) {
		for (int i = 1; i < (int)V.size(); i++) {
			res += dsu.merge(V[i], V[i-1]) * w;
		}
	}

	if (dsu.cc != 1) return cout << -1 << endl, 0;
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

