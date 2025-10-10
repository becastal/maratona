#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

struct Dsu {
	vector<int> id, sz;
	Dsu(int n) : id(n), sz(n, 1) {
		iota(id.begin(), id.end(), 0);
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	void merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		if (sz[i] < sz[j]) swap(i, j);
		sz[i] += sz[j], id[j] = i;
	}

	int tam(int i) {
		return sz[find(i)];
	}
};

int solve() {
	int n; cin >> n;

	vector<int> A(n), U(n);
	for (int& i : A) cin >> i;
	iota(all(U), 0);

	vector<vector<int>> G(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	auto calc = [&]() {
		Dsu dsu(n);
		vector<int> vis(n, 0);

		ll res = 0;
		for (int u : U) {
			vis[u] = 1;
			for (int v : G[u]) if (vis[v]) {
				res += 1LL * A[u] * dsu.tam(u) * dsu.tam(v);
				dsu.merge(u, v);
			}
		}

		return res;
	};

	sort(all(U), [&A](int i, int j) { return A[i] < A[j]; });
	ll res = calc();

	reverse(all(U));
	res -= calc();

	cout << res << endl;

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

