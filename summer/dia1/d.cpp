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
	DSU(int n) : id(n), sz(n, 1) {
		iota(id.begin(), id.end(), 0);
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	void merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		if (sz[i] < sz[j]) swap(i, j);
		sz[i] += sz[j], id[j] = i;
	}
};

int main()
{
    _;

	int n, m; cin >> n >> m;
	vector<tuple<ll, int, int>> ed(m);
	for (auto& [w, u, v] : ed) {
		cin >> u >> v >> w; u--, v--;
	}

	DSU dsu(n);
	sort(ed.begin(), ed.end());
	vector<vector<pair<int, ll>>> g(n);
	for (auto& [w, u, v] : ed) {
		if (dsu.find(u) != dsu.find(v)) {
			dsu.merge(u, v);
			g[u].emplace_back(v, w);
			g[v].emplace_back(u, w);
		}
	}

	ll total = 0;
	vector<int> res;
	function<void(int, int)> dfs = [&](int u, int pai) {
		res.push_back(u);
		for (auto [v, w] : g[u]) {
			if (v == pai) continue;
			dfs(v, u);
			total += 2LL * w;
			res.push_back(u);
		}
	};

	dfs(0, -1);
   	cout << total << endl; 
	cout << (int)res.size() << endl;
	for (int i : res) cout << i + 1 << ' '; cout << endl;

    return(0);
}
