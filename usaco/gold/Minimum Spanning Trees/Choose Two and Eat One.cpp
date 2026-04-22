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

	Dsu (int n_) : n(n_), id(n), sz(n, 1) {
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
};

int exp(int a, int b, int m) {
	if (!b) return 1;
	int res = (b & 1 ? a : 1);
	return exp(a * a % m, b / 2, m) * res % m;
}

int solve() {
	int n, m; cin >> n >> m;

	vector<int> A(n);
	vector<array<int, 3>> E(n * (n - 1) / 2);
	
	auto peso = [&](int a, int b) {
		return (exp(a, b, m) + exp(b, a, m)) % m;
	};

	for (int i = 0, p = 0; i < n; i++) {
		cin >> A[i];
		for (int j = 0; j < i; j++) {
			E[p++] = {peso(A[i], A[j]), i, j};	
		}
	}

	sort(rall(E));
	
	Dsu dsu(n);
	int res = 0;
	for (auto [w, a, b] : E) {
		res += dsu.merge(a, b) * w;
	}
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

