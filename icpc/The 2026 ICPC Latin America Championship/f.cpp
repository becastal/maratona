#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int OFF = 70;
const int MAX = 150;
int M[MAX][MAX];

struct Dsu {
	int n;
	vector<int> sz, id;

	Dsu(int n_) : n(n_), sz(n, 1), id(n) {
		iota(all(id), 0);
	}

	int find(int u) {
		return (u == id[u] ? u : id[u] = find(id[u]));
	}

	int merge(int u, int v) {
		if ((u = find(u)) == (v = find(v))) return 0;
		if (sz[u] < sz[v]) swap(u, v);
		sz[u] += sz[v];
		id[v] = id[u];
		return 1;
	}
};


int solve() {
	int n; cin >> n;
	memset(M, -1, sizeof(M));
	vector<int> C(n);
	for (int& i : C) {
		cin >> i;
	}

	int n_ = n, s = 1;
	vector<int> B;
	while (n_ > 0) {
		int take = min(n_, s);
		B.push_back(take);
		n_ -= take;
		s++;
	}

	const vector<array<int, 2>> movs = {
		{-2, 0}, {2, 0}, {-1, 1}, {1, 1}, {-1, -1}, {1, -1}
	};

	int m = (int)B.size(), res = 0;


	for (int mask = 0; mask < (1LL << (m - 1)); mask++) {
		vector<array<int, 2>> P(n);

		int l = 0, r = 0, p = 0;
		P[p] = {0, 0};
		M[0 + OFF][0 + OFF] = p;
		p++;

		for (int i = 1; i < m; i++) {
			if (mask >> (i - 1) & 1) {
				l -= 2;
				for (int j = 0, l_ = l; j < B[i]; j++) {
					P[p] = {l_++, j};
					M[P[p][0] + OFF][P[p][1] + OFF] = p;
					p++;
				}
			} else {
				r += 2;
				for (int j = 0, r_ = r; j < B[i]; j++) {
					P[p] = {r_--, j};
					M[P[p][0] + OFF][P[p][1] + OFF] = p;
					p++;
				}
			}
		}

		Dsu dsu(n);
		for (int pi = 0; pi < n; pi++) {
			auto [ui, uj] = P[pi];

			for (auto [di, dj] : movs) {
				int vi = ui + di, vj = uj + dj;
				if (vi + OFF < 0 or vi + OFF >= MAX or vj + OFF < 0 or vj + OFF >= MAX) continue;

				int pj = M[vi + OFF][vj + OFF];
				if (pj != -1 and C[pi] == C[pj]) {
					dsu.merge(pi, pj);
				}
			}
		}

		for (int i = 0; i < n; i++) {
			res = max(res, dsu.sz[dsu.find(i)]);
			auto [ui, uj] = P[i];
			M[ui + OFF][uj + OFF] = -1;
		}
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
