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
    
	vector<vector<pair<int, int>>> g(n);
	vector<pair<int, int>> ed(m); 
	vector<int> usei(m, 0); 

	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[u].emplace_back(v, i);
		g[v].emplace_back(u, i);
		ed[i].f = u, ed[i].s = v;
	}

	int comps = 0;
	DSU dsu(n);

	vector<int> vis(n, 0), cor(n, -1), repr(n, -1);
	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;
		cor[u] = comps;
		
		for (auto [v, idx] : g[u]) {
			if (vis[v]) continue;
			dsu.merge(u, v);
			usei[idx] = 1;
			dfs(v);
		}
	};

	set<int> falta;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			falta.insert(comps);
			repr[comps] = i;
			dfs(i);
			comps++;
		}
	}

	int pri = 1;
	vector<tuple<int, int, int>> res;
	for (int i = 0; i < m; i++) {
		if (usei[i]) continue;
		auto [u, v] = ed[i];
		if (dsu.find(u) != dsu.find(v)) continue;

		if (pri) {
			falta.erase(cor[u]);
			pri = 0;
		}

		for (int j : falta) {
			if (dsu.find(u) != dsu.find(repr[j])) {
				res.emplace_back(i+1, v+1, repr[j]+1);
				falta.erase(j);
				dsu.merge(u, repr[j]);
				break;
			}
		}
	}

	cout << res.size() << endl;
	for (auto [a, b, c] : res) {
		cout << a << ' ' << b << ' ' << c << endl;
	}

    return(0);
}
