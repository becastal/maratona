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
		return (u == id[u] ? u : id[u] = find(id[u]));
	}

	int merge(int u, int v) {
		if ((u = find(u)) == (v = find(v))) return 0;
		if (sz[u] < sz[v]) swap(u, v);
		id[v] = u;
		sz[u] += sz[v];
		return 1;
	}
};

signed solve() {
	int n, m, k; cin >> n >> m >> k;
	
	vector<array<int, 3>> A(k);
	for (auto& [a, b, c] : A) {
		cin >> a >> b >> c;
	}

	auto intercepta = [](array<int, 3> A, array<int, 3> B) {
		auto [a, b, di] = A;
		auto [c, d, dj] = B;
		return (c - a) * (c - a) + (d - b) * (d - b) <= di * di + 2 * di * dj + dj * dj;	
	};

	Dsu dsu(k + 4);
	for (int i = 0; i < k; i++) {
		auto [a, b, di] = A[i];

		// cima
		if (intercepta(A[i], {a, 0, 0})) {
			dsu.merge(i, k);	
		}

		// direita
		if (intercepta(A[i], {n, b, 0})) {
			dsu.merge(i, k + 1);	
		}

		// baixo
		if (intercepta(A[i], {a, m, 0})) {
			dsu.merge(i, k + 2);
		}

		// esquerda
		if (intercepta(A[i], {0, b, 0})) {
			dsu.merge(i, k + 3);
		}

		for (int j = i + 1; j < k; j++) {
			if (intercepta(A[i], A[j])) {
				dsu.merge(i, j);	
			}
		}
	}

	// ruins:
	// 	cima e baixo,
	// 	direita e esquerda, 
	// 	cima e esquerda,
	// 	direita e baixo
	vector<array<int, 2>> ruim = {
		{0, 2},
		{1, 3},
		{0, 3},
		{1, 2},
	};

	for (auto [i, j] : ruim) {
		if (dsu.find(k + i) == dsu.find(k + j)) {
			return cout << "N" << endl, 0;
		}
	}

	cout << "S" << endl;

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
