#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

/*

harder version of: https://codeforces.com/gym/102346/problem/A

process queries by non decreasing radius
also process connections between trees and other trees and borders in non decreasing distance

the query answering can be made in a cleaner way with a small 4node graph i think

*/

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
		id[v] = id[u];
		return 1;
	}

	int mesmo(int u, int v) {
		return find(u) == find(v);
	}
};

int solve() {
	int n, m, w, h; cin >> n >> m >> w >> h;

	vector<tuple<long double, int, int, int>> Ev;
	vector<array<int, 3>> A(n);
	for (int i = 0; i < n; i++) {
		auto& [x, y, r] = A[i];
		cin >> x >> y >> r;	
	}

	auto dist = [&](int x1, int y1, int x2, int y2) -> long double {
		return sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	};

	auto Paredes = [&](int x, int y) {
		return vector<array<int, 2>> {
			{0, y},	// esquerda
			{x, 0},	// baixo
			{w, y},	// direita
			{x, h},	// cima
		};
	};

	for (int i = 0; i < n; i++) {
		auto [xi, yi, ri] = A[i];
		for (int j = i + 1; j < n; j++) { 
			auto [xj, yj, rj] = A[j];

			long double d = dist(xi, yi, xj, yj) - ri - rj;
			Ev.emplace_back(d, 1, i, j);
		}

		auto Parede = Paredes(xi, yi);
		for (int j = 0; j < 4; j++) {
			auto [xj, yj] = Parede[j];
			
			long double d = dist(xi, yi, xj, yj) - ri;
			Ev.emplace_back(d, 1, i, n + j);
		}
	}
	
	vector<array<int, 2>> B(m);
	for (int i = 0; i < m; i++) {
		auto& [r, e] = B[i];
		cin >> r >> e;
		Ev.emplace_back(2 * r, 0, i, e);
	}
	sort(all(Ev));

	Dsu dsu(n + 4);

	vector<int> Res(m), Alc(4, 0b1111);
	// (1 = bottom-left, 2 = bottom-right, 3 = top-right, 4 = top-left)

	for (auto [val, tp, a, b] : Ev) {
		if (tp == 1) {
			dsu.merge(a, b);

			if (dsu.mesmo(n, n + 1)) { // esquerda e baixo
				Alc[0] &= 0b0001;
				Alc[1] &= 0b1110;
				Alc[2] &= 0b1110;
				Alc[3] &= 0b1110;
			}

			if (dsu.mesmo(n, n + 2)) { // esquerda e direita
				Alc[0] &= 0b0011;
				Alc[1] &= 0b0011;
				Alc[2] &= 0b1100;
				Alc[3] &= 0b1100;
			}

			if (dsu.mesmo(n, n + 3)) { // esquerda e cima
				Alc[0] &= 0b0111;
				Alc[1] &= 0b0111;
				Alc[2] &= 0b0111;
				Alc[3] &= 0b1000;
			}

			if (dsu.mesmo(n + 1, n + 2)) { // baixo e direita
				Alc[0] &= 0b1101;
				Alc[1] &= 0b0010;
				Alc[2] &= 0b1101;
				Alc[3] &= 0b1101;
			}

			if (dsu.mesmo(n + 1, n + 3)) { // baixo e cima
				Alc[0] &= 0b1001;
				Alc[1] &= 0b0110;
				Alc[2] &= 0b0110;
				Alc[3] &= 0b1001;
			}

			if (dsu.mesmo(n + 2, n + 3)) { // direita e cima
				Alc[0] &= 0b1011;
				Alc[1] &= 0b1011;
				Alc[2] &= 0b0100;
				Alc[3] &= 0b1011;
			}
			
		} else if (tp == 0) {
			int in = b, id = a;	
			Res[id] = Alc[in - 1];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 4; j++) if (Res[i] >> j & 1) {
			cout << char('1' + j);
		}
		cout << endl;
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

