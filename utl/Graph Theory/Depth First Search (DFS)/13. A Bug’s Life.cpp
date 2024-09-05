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
	int n, m; cin >> n >> m;

	vector<vector<int>> g(n);
	vector<int> cor(n, -1);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	function<bool(int, int)> dfs = [&] (int u, int c) {
		cor[u] = c;

		for (int v : g[u]) {
			if (cor[v] == -1) {
				if (!dfs(v, !c)) return 0;
			} else if (cor[v] == c) return 0;
		}
		return 1;
	};

	for (int i = 0; i < n; i++) {
		if (cor[i] == -1) {
			if (!dfs(i, 0)) return cout << "Suspicious bugs found!" << endl, 0;
		}
	}

	cout << "No suspicious bugs found!" << endl;
	return 0;
}

int main()
{
    _;

	int t; cin >> t;
	for (int i = 1; i<= t; i++) {
		cout << "Scenario #" << i << ":" << endl;
		solve();
	}
    
    return(0);
}
