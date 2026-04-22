#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
//#define int ll

struct Dsu {
	int n;
	vector<int> id, sz;
	Dsu(int n_) : n(n_), id(n), sz(n, 1) {
		iota(all(id), 0);
	};

	int find(int u) {
		return (u == id[u] ? u : id[u] = find(id[u]));
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

	map<array<int, 2>, int> Id;
	vector<array<int, 3>> E(m);
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		if (u > v) swap(u, v);
		E[i] = {u, v, w};
		Id[{u, v}] = i;
	}
	vector<int> O(m);
	iota(all(O), 0);
	sort(all(O), [&E](int a, int b) {
		return E[a][2] < E[b][2];
	});

	vector<int> Res(m), L(m, 0), R(m, m-1);
	vector<vector<int>> Mid(m);
	for (int rep = 0, lim = __lg(m) + 2; rep < lim; rep++) {
		for (int i = 0; i < m; i++) {
			if (L[i] <= R[i]) {
				int mid = L[i] + (R[i] - L[i]) / 2;
				Mid[mid].push_back(i);
			}
		}

		Dsu dsu(n);
		for (int mid = 0; mid < m; mid++) {
			auto [u, v, w] = E[O[mid]];
			dsu.merge(u, v);

			for (int i : Mid[mid]) {
				auto [a, b, w_] = E[i];

				if (dsu.find(a) == dsu.find(b)) {
					R[i] = mid - 1;	
					Res[i] = w;
				} else {
					L[i] = mid + 1;	
				}
			}
			Mid[mid].clear();
		}
	}

	Dsu dsu(n);
	int mst = 0;
	for (int i = 0; i < m; i++) {
		auto [u, v, w] = E[O[i]];
		mst += dsu.merge(u, v) * w;
	}

	for (int i = 0; i < m; i++) {
		//cout << E[i][0] + 1 << " " << E[i][1] + 1 << ": " << Res[i] << endl;
		Res[i] = mst - Res[i] + E[i][2];
		//cout << Res[i] << endl;
	}

	int q; cin >> q;
	while (q--) {
		int u, v; cin >> u >> v; u--, v--;
		if (u > v) swap(u, v);
		cout << Res[Id[{u, v}]] << endl;
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

