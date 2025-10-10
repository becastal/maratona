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
	int n; cin >> n;
	int m = __lg(n) + 1;
	vector<vector<int>> G(n);
	
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);	
		G[v].push_back(u);	
	}

	auto u_dist = [&](int in) {
		int d_res = -1, res = 0;
		function<void(int, int, int)> dfs = [&](int u, int p, int d) {
			if (d_res < d) {
				d_res = d;
				res = u;
			}
			for (int v : G[u]) if (v != p) {
				dfs(v, u, d + 1);
			}
		};
		dfs(in, -1, 0);
		return res;
	};

	int diam_a = u_dist(0), diam_b = u_dist(diam_a);

	vector<int> Da(n, 0), Db(Da);
	vector<vector<int>> Pa(n, vector<int>(m, 0)), Pb(Pa);

	function<void(int, int, vector<int>&, vector<vector<int>>&)> dfs =
		[&](int u, int p, vector<int>& D, vector<vector<int>>& P) {
		for (int v : G[u]) if (v != p) {
			D[v] = D[u] + 1;
			dfs(v, P[v][0] = u, D, P);
		}
	};
	dfs(diam_a, -1, Da, Pa);
	dfs(diam_b, -1, Db, Pb);

	for (int j = 1; j < m; j++) {
		for (int i = 0; i < n; i++) {
			Pa[i][j] = Pa[Pa[i][j-1]][j-1];
			Pb[i][j] = Pb[Pb[i][j-1]][j-1];
		}
	}

	auto kth = [&m](int u, int k, vector<vector<int>>& P) {
		for (int i = 0; i < m; i++) if (k >> i & 1) {
			u = P[u][i];
		}
		return u;
	};

	int q; cin >> q;
	while (q--) {
		int u, k; cin >> u >> k; u--;

		auto& P = Da[u] > Db[u] ? Pa : Pb;
		auto& D = Da[u] > Db[u] ? Da : Db;

		if (D[u] >= k) cout << kth(u, k, P) + 1 << endl;
		else cout << -1 << endl;
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
