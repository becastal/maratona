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
	int n, k; cin >> n >> k;

	vector<vector<int>> g(n), gi(n);
	vector<int> p(n), q(n), vis(n, 0), comp(n);

	for (int& i : p) cin >> i, i--;
	for (int& i : q) cin >> i, i--;

	for (int i = 1; i < n; i++) {
		g[p[i-1]].push_back(p[i]);
		gi[p[i]].push_back(p[i-1]);

		g[q[i-1]].push_back(q[i]);
		gi[q[i]].push_back(q[i-1]);
	}

	stack<int> S;
	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;
		for (int i = 0; i < (int) g[u].size(); i++)
			if (!vis[g[u][i]]) dfs(g[u][i]);

		S.push(u);
	};

	for (int i = 0; i < n; i++) {
		if (!vis[i]) dfs(i);
	}

	int id = 0;
	function<void(int)> dfs2 = [&](int u) {
		vis[u] = 1;
		comp[u] = id;
		for (int v : gi[u]) {
			if (!vis[v]) dfs2(v);
		}
	};

	fill(vis.begin(), vis.end(), 0);
	while (S.size()) {
		int u = S.top(); S.pop();
		if (vis[u]) continue;
		dfs2(u);
		id++;
	}
	
	if (id < k) return cout << "NO" << endl, 0;

	cout << "YES" << endl;
	for (int i = 0; i < n; i++) {
		cout << char('a' + min(comp[i], k-1));
	}
	cout << endl;

	return(0);
}

int main()
{
    _;

	int t = 1;// cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
