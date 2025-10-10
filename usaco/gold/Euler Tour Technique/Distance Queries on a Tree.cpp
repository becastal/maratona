#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

struct Bit {
	int n;
	vector<ll> F;
	Bit(int n_) : n(n_), F(n_+1, 0) {};
	void update(int i, ll x) {
		for (++i; i <= n; i+=i&-i) F[i] += x;
	};
	ll pref(int i) {
		ll res = 0;
		for (++i; i; i-=i&-i) res += F[i];
		return res;
	};
};

int solve() {
	int n; cin >> n;

	vector<vector<array<int, 2>>> G(n);
	vector<array<int, 3>> E(n-1);

	vector<ll> W(n, 0);
	for (auto& [u, v, w] : E) {
		cin >> u >> v >> w; u--, v--;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}

	int m = __lg(n) + 1, t = 0;
	vector<int> D(n, 0), L(n), R(n);
	vector<vector<int>> P(n, vector<int>(m, 0));
	function<void(int, int)> dfs = [&](int u, int p) {
		L[u] = t++;
		for (auto [v, w] : G[u]) if (v != p) {
			D[v] = D[u] + 1;
			W[v] = W[u] + w;
			P[v][0] = u;
			dfs(v, u);
		}
		R[u] = t-1;
	};
	dfs(0, -1);

	for (auto& [u, v, w] : E) {
		if (D[u] > D[v]) swap(u, v);
	}

	for (int j = 1; j < m; j++) {
		for (int i = 0; i < n; i++) {
			P[i][j] = P[P[i][j-1]][j-1];
		}
	}

	auto kth = [&](int u, int k) {
		for (int j = m-1; j >= 0; j--) if (k & (1 << j)) {
			u = P[u][j];
		}
		return u;
	};

	auto lca = [&](int a, int b) {
		if (D[a] < D[b]) swap(a, b);

		a = kth(a, D[a] - D[b]);
		if (a == b) return a;

		for (int j = m-1; j >= 0; j--) {
			if (P[a][j] != P[b][j]) {
				a = P[a][j];
				b = P[b][j];
			}
		}
		return P[a][0];
	};

	Bit bit(n+2);
	vector<ll> Wi(n-1);
	for (int i = 0; i < n-1; i++) {
		Wi[i] = E[i][2];
	}

	int q; cin >> q;
	while (q--) {
		int tp; cin >> tp;

		if (tp == 1) {
			int i, w; cin >> i >> w; i--;
			int u = E[i][1];	

			ll dif = w - Wi[i];
			bit.update(L[u], +dif);
			bit.update(R[u]+1, -dif);
			Wi[i] = w;
		} else {
			int a, b; cin >> a >> b; a--, b--;
			int c = lca(a, b);

			ll res = W[a] + W[b] - 2 * W[c];
			res += (bit.pref(L[a]) + bit.pref(L[b]) - 2 * bit.pref(L[c]));
			cout << res << endl;
		}
	}

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


