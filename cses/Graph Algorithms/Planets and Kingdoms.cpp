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

int solve() {
	int n, m, t = 0; cin >> n >> m;

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);	
	}

	vector<int> vis(n, 0), comp(n), id(n);
	stack<int> s;
	function<int(int)> dfs = [&](int i) {
		int lo = id[i] = t++;
		s.push(i);
		vis[i] = 2;

		for (int j : g[i]) {
			if (!vis[j]) lo = min(lo, dfs(j));
			else if (vis[j] == 2) lo = min(lo, id[j]);
		}

		// aresta de i pro pai eh uma ponte (no caso nao direcionado)
		if (lo == id[i]) while (1) {
			int u = s.top(); s.pop();
			vis[u] = 1, comp[u] = i;
			if (u == i) break;
		}

		return lo;
	};
	for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);

	auto comp_ = comp;
	sort(comp_.begin(), comp_.end());
	comp_.erase(unique(comp_.begin(), comp_.end()), comp_.end());

	auto val = [&](int u) {
		return lower_bound(comp_.begin(), comp_.end(), u) - comp_.begin() + 1;
	};

	cout << comp_.size() << endl;
	for (int i = 0; i < n; i++) {
		cout << val(comp[i]) << " \n"[i==n-1];
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
