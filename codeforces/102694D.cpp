#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n, mm; cin >> n >> mm;
	assert(mm == n-1);

	vector<vector<array<int, 2>>> G(n);
	for (int i = 0, u, v, w; i < n-1; i++) {
		cin >> u >> v >> w; u--, v--;	
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}

	int m = __lg(n) + 1;
	vector<int> D(n, 0);
	vector<vector<int>> P(n, vector<int>(m, 0)), W(n, vector<int>(m, 0));
	function<void(int, int)> dfs = [&](int u, int p) {
		for (auto [v, w] : G[u]) if (v != p) {
			D[v] = D[u] + 1;
			P[v][0] = u;
			W[v][0] = w;
			dfs(v, u);
		}
	};
	dfs(0, -1);

	for (int j = 1; j < m; j++) {
		for (int i = 0; i < n; i++) {
			P[i][j] = P[P[i][j-1]][j-1];
			W[i][j] = min(W[i][j-1], W[P[i][j-1]][j-1]);
		}
	}

	auto min_path = [&](int a, int b) {
		if (D[b] > D[a]) swap(a, b);

		int res = INF, k = D[a] - D[b];
		for (int i = 0; i < m; i++) if (k >> i & 1) {
			res = min(res, W[a][i]);
			a = P[a][i];
		}
		if (a == b) return res;

		for (int i = m-1; i >= 0; i--) {
			if (P[a][i] != P[b][i]) {
				res = min({res, W[a][i], W[b][i]});
				a = P[a][i];
				b = P[b][i];
			}
		}

		res = min({res, W[a][0], W[b][0]});
		return res;
	};

	int q; cin >> q;
	while (q--) {
		int u, v; cin >> u >> v; u--, v--;
		cout << min_path(u, v) << endl;
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
