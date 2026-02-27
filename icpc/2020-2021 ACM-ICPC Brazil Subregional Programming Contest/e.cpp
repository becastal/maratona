#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MAX = 2e5+10;
int bit[MAX];
int solve() {
	int n, q; cin >> n >> q;
	int LOG = __lg(n) + 2;
	vector<vector<int>> P(n, vector<int>(LOG));

	vector<vector<int>> G(n);
	vector<int> V(n);
	for (int i = 0; i < n; i++) {
		cin >> V[i] >> P[i][0]; P[i][0]--;
		if (i) {
			G[P[i][0]].push_back(i);
		}
	}

	int t = 0;
	vector<int> E(n), D(n), L(n), R(n);
	function<void(int)> dfs = [&](int u) {
		E[t] = u;
		L[u] = t++;
		for (int v : G[u]) {
			D[v] = D[u] + 1;
			dfs(v);
		}
		R[u] = t;
	};
	dfs(0);

	for (int i = 1; i < LOG; i++) {
		for (int j = 0; j < n; j++) {
			P[j][i] = P[P[j][i-1]][i-1];
		}
	}

	function<int(int, int)> hiperpai = [&](int u, int r) {
		for (int i = LOG - 1; i >= 0; i--) {
			int pu = P[u][i];
			if (V[pu] <= r) {
				u = P[u][i];
			}
		}
		return u;
	};

	function<void(int, int)> update = [&](int i, int x) {
		for (i++; i < MAX; i+=i&-i) {
			bit[i] += x;
		}
	};

	function<int(int)> pref = [&](int i) {
		int res = 0;
		for (i++; i; i-=i&-i) {
			res += bit[i];
		}
		return res;
	};

	vector<vector<array<int, 3>>> Ev(n + 1);
	while (q--) {
		int o, l, r; cin >> o >> l >> r; o--;
		int u = hiperpai(o, r);
		Ev[L[u]].push_back({l, r, 0});
		Ev[R[u]].push_back({l, r, 1});
	}

	vector<int> Res(n);
	for (int i = 0; i < n; i++) {
		for (auto [l, r, tp] : Ev[i]) {
			update(l, tp ? -1 : +1);
			update(r + 1, tp ? +1 : -1);
		}
		Res[E[i]] = pref(V[E[i]]);
	}

	for (int i = 0; i < n; i++) {
		cout << Res[i] << " \n"[i==n-1];
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

