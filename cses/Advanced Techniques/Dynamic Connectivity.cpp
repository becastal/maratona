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
	stack<array<int, 2>> s;

	Dsu(int n_) : n(n_), cc(n_), id(n_), sz(n_, 1) {
		iota(all(id), 0);
	}
	int find(int a) {
		while (a != id[a]) a = id[a];
		return a;
	}
	void merge(int a, int b) {
		if ((a = find(a)) == (b = find(b))) return s.push({-1, -1});
		cc--;
		if (sz[a] > sz[b]) swap(a, b);
		s.push({a, b});
		id[a] = b;
		sz[b] += sz[a];
	}
	void rollback() {
		auto [a, b] = s.top(); s.pop();
		if (a == -1) return;
		sz[b] -= sz[a];
		id[a] = a;
		cc++;
	}
};

int solve() {
	int n, m, k; cin >> n >> m >> k;

	map<array<int, 2>, int> Pos;
	vector<vector<array<int, 2>>> Seg(4 * (k + 1) + 5);

	auto add = [&](auto&& self, int p, int l, int r, int ql, int qr, array<int, 2> edge) -> void {
		if (ql > r or qr < l) return;
		if (ql <= l and r <= qr) {
			Seg[p].push_back(edge);
			return;
		}
		int mid = (l + r) / 2;
		self(self, 2 * p, l, mid, ql, qr, edge);
		self(self, 2 * p + 1, mid + 1, r, ql, qr, edge);
	};

	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b; a--, b--;
		if (a > b) swap(a, b);
		Pos[{a, b}] = 0;
	}

	for (int i = 1, tp, a, b; i <= k; i++) {
		cin >> tp >> a >> b; a--, b--;
		if (a > b) swap(a, b);
		array<int, 2> edge{a, b};

		if (tp == 1) {
			Pos[edge] = i;
		} else {
			int l = Pos[edge], r = i - 1;
			if (l <= r) add(add, 1, 0, k, l, r, edge);
			Pos.erase(edge);
		}
	}

	for (auto [edge, l] : Pos) {
		add(add, 1, 0, k, l, k, edge);
	}

	Dsu dsu(n);
	vector<int> Res(k + 1);

	auto calc = [&](auto&& self, int p, int l, int r) -> void {
		int cont = 0;
		for (auto [a, b] : Seg[p]) {
			dsu.merge(a, b);
			cont++;
		}

		if (l == r) {
			Res[l] = dsu.cc;
		} else {
			int mid = (l + r) / 2;
			self(self, 2 * p, l, mid);
			self(self, 2 * p + 1, mid + 1, r);
		}

		while (cont--) dsu.rollback();
	};

	calc(calc, 1, 0, k);

	for (int i = 0; i <= k; i++) {
		cout << Res[i] << " \n"[i == k];
	}

	return 0;
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
