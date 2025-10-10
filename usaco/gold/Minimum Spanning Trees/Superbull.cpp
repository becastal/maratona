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
		return id[u] = (u == id[u] ? u : find(id[u]));
	}

	void merge(int u, int v) {
		if ((u = find(u)) == (v = find(v))) return;
		if (sz[v] > sz[u]) swap(u, v);
		id[v] = u;
		sz[u] += sz[v];
	}
};

int solve() {
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	vector<array<int, 3>> E(n * (n - 1) / 2);
	for (int i = 0, p = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			E[p++] = {A[i] ^ A[j], i, j};
		}
	}

	Dsu dsu(n);
	sort(rall(E));
	ll res = 0;
	for (auto [w, u, v] : E) {
		if (dsu.find(u) != dsu.find(v)) {
			dsu.merge(u, v);
			res += w;
		}
	}
	cout << res << endl;

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("superbull");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

