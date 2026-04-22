#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MOD = 998244353;

int pot(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

struct Seg {
	struct Node {
		int a, b;
	};

	int n;
	vector<Node> st;

	Seg() { }
	Seg(int n_) : n(n_), st(2 * n, {0, 1}) { }

	Node merge(Node L, Node R) {
		return {(L.a + L.b * R.a) % MOD, L.b * R.b % MOD};
	}

	void update(int p, Node v) {
		for (st[p += n] = v; p > 1; p >>= 1) {
			st[p >> 1] = merge(st[p >> 1 << 1], st[p >> 1 << 1 | 1]);
		}
	}

	Node query(int l, int r) {
		Node L = {0, 1}, R = {0, 1};
		for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) {
				L = merge(L, st[l++]);
			}
			if (r & 1) {
				R = merge(st[--r], R);
			}
		}
		return merge(L, R);
	}
};

int solve() {
	int n, q; cin >> n >> q;
	vector<vector<int>> g(n + 1);
	vector<int> p(n + 1), A(n + 1);
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		g[p[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}

	vector<int> sz(n + 1, 1), heavy(n + 1, -1);
	for (int i = n; i >= 1; i--) {
		for (int c : g[i]) {
			sz[i] += sz[c];
			if (heavy[i] == -1 or sz[c] > sz[heavy[i]]) {
				heavy[i] = c;
			}
		}
	}

	vector<int> light_prod(n + 1, 1), light_zero(n + 1), coef(n + 1), f(n + 1);
	for (int i = n; i >= 1; i--) {
		if (g[i].empty()) {
			f[i] = A[i];
			continue;
		}

		for (int c : g[i]) {
			if (c == heavy[i]) {
				continue;
			}
			if (f[c] == 0) {
				light_zero[i]++;
			}
			else {
				light_prod[i] = light_prod[i] * f[c] % MOD;
			}
		}

		coef[i] = (light_zero[i] ? 0 : light_prod[i]);
		f[i] = (A[i] + coef[i] * f[heavy[i]]) % MOD;
	}

	vector<int> head(n + 1), pos(n + 1), tail(n + 1, -1);
	int timer = 0;
	vector<int> st = {1};
	while (st.size()) {
		int h = st.back();
		st.pop_back();

		for (int u = h; u != -1; u = heavy[u]) {
			head[u] = h;
			pos[u] = timer++;
			for (int c : g[u]) {
				if (c != heavy[u]) {
					st.push_back(c);
				}
			}
			if (heavy[u] == -1) {
				tail[h] = pos[u];
			}
		}
	}

	Seg seg(n);
	for (int i = 1; i <= n; i++) {
		seg.update(pos[i], {A[i], heavy[i] == -1 ? 0 : coef[i]});
	}

	vector<int> head_val(n + 1);
	for (int i = 1; i <= n; i++) {
		if (head[i] == i) {
			head_val[i] = f[i];
		}
	}

	auto chain_value = [&](int h) {
		return seg.query(pos[h], tail[h]).a;
	};

	auto change_light = [&](int u, int oldv, int newv) {
		if (oldv == 0) {
			light_zero[u]--;
		}
		else {
			light_prod[u] = light_prod[u] * pot(oldv, MOD - 2) % MOD;
		}

		if (newv == 0) {
			light_zero[u]++;
		}
		else {
			light_prod[u] = light_prod[u] * newv % MOD;
		}

		coef[u] = (light_zero[u] ? 0 : light_prod[u]);
	};

	while (q--) {
		int v, x; cin >> v >> x;
		A[v] = x;
		seg.update(pos[v], {A[v], heavy[v] == -1 ? 0 : coef[v]});

		int h = head[v], now = chain_value(h);
		while (now != head_val[h]) {
			int old = head_val[h];
			head_val[h] = now;

			if (h == 1) {
				break;
			}

			int u = p[h];
			change_light(u, old, now);
			seg.update(pos[u], {A[u], heavy[u] == -1 ? 0 : coef[u]});

			h = head[u];
			now = chain_value(h);
		}

		cout << head_val[1] << endl;
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
