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

struct DSU {
	vector<int> id, sz;
	int cc;
	DSU(int n) : id(n), sz(n, 1), cc(n) {
		iota(id.begin(), id.end(), 0);
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	void merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		if (sz[i] < sz[j]) swap(i, j);
		sz[i] += sz[j], id[j] = i, cc--;
	}
};

int solve() {
	int n, m1, m2; cin >> n >> m1 >> m2;
	vector<vector<int>> f(n), g(n);

	for (int i = 0, u, v; i < m1; i++) {
		cin >> u >> v; u--, v--;
		f[u].push_back(v);
		f[v].push_back(u);
	}

	DSU dsug(n);
	for (int i = 0, u, v; i < m2; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
		dsug.merge(u, v);
	}

	int res = 0, ccf = 0;
	vector<int> vis(n, 0);
	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;

		for (int v : f[u]) {
			if (vis[v]) continue;
			if (dsug.find(u) != dsug.find(v)) {
				res++;
				continue;
			}
			dfs(v);
		}
	};

	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		ccf++;
		dfs(i);
	}

	cout << res + (ccf - dsug.cc) << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
