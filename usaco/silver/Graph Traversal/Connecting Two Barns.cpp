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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int solve() {
	int n, m; cin >> n >> m;

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<vector<int>> c;
	vector<int> comp(n, -1);
	function<void(int)> dfs = [&](int u) {
		comp[u] = (int)c.size() - 1;
		c.back().push_back(u);
		for (int v : g[u]) {
			if (comp[v] != -1) continue;
			dfs(v);
		}
	};

	for (int i = 0; i < n; i++) {
		if (comp[i] != -1) continue;
		c.push_back({});
		dfs(i);
	}
	
	for (auto& vi : c) {
		sort(vi.begin(), vi.end());
	}

	auto f = [](int x, vector<int>& v) {
		auto it = lower_bound(v.begin(), v.end(), x);
		ll res = LINF;
		if (it != v.end()) res = min(res, ll(x - *it) * (x - *it));
		if (it != v.begin()) res = min(res, ll(x - *(--it)) * (x - *it));
		return res;
	};

	ll res = LINF;
	for (int i = 0; i < c[comp[0]].size(); i++) {
		res = min(res, f(c[comp[0]][i], c[comp[n-1]]));
	}

	for (int i = 0; i < c.size(); i++) {
		if (i == comp[0] or i == comp[n-1]) continue;
		ll ab = LINF, bc = LINF;
		for (int j = 0; j < c[i].size(); j++) {
			ab = min(ab, f(c[i][j], c[comp[0]]));
			bc = min(bc, f(c[i][j], c[comp[n-1]]));
		}
		res = min(res, ab + bc);
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;
	setIO("");

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}

