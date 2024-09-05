#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main()
{
    _;

	int n, m; cin >> n >> m;
	vector<pair<int, int>> edges(m);
	vector<vector<ll>> d(n, vector<ll>(n, LINF));
	vector<vector<vector<ll>>> exc(n, vector<vector<ll>>(n, vector<ll>(n, INF)));

	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		d[u][v] = w;
		d[v][u] = w;
		edges[i] = {u, v};
	}
	for (int i = 0; i < n; i++) {
		d[i][i] = 0;
	}

	auto floyd_warshall = [&](int l, int r) {
		for (int w = l; w < r; w++) {
			for (int u = 0; u < n; u++) {
				for (int v = 0; v < n; v++) {
					d[u][v] = min(d[u][v], d[u][w] + d[w][v]);
				}
			}
		}
	};
    
	function<void(int, int)> solve = [&] (int l, int r) {
		if (r-l == 1)  {
			exc[l] = d;
			return;
		}

		int mi = (l+r)/2;
		vector<vector<ll>> cp = d;

		floyd_warshall(l, mi);
		solve(mi, r);

		d = cp;

		floyd_warshall(mi, r);
		solve(l, mi);
	};
	solve(0, n);

	for (auto [u, v] : edges) {
		ll res = LINF;
		for (int mi = 0; mi < n; mi++) {
			if (mi == u or mi == v) continue;
			res = min(res, exc[v][u][mi] + exc[u][mi][v]);
		}
		cout << (res != LINF ? res : -1) << endl;
	}

    return(0);
}
