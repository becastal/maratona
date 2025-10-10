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
	int n; cin >> n;
	vector<vector<int>> g1(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		g1[u].push_back(v);	
		g1[v].push_back(u);	
	}

	int m; cin >> m;
	vector<vector<int>> g2(m);
	for (int i = 0, u, v; i < m-1; i++) {
		cin >> u >> v; u--, v--;
		g2[u].push_back(v);	
		g2[v].push_back(u);	
	}

	auto dfs = [](int in, vector<vector<int>>& g) {
		vector<int> d(g.size(), -1);	d[in] = 0;
		stack<int> s; s.push(in);

		while (s.size()) {
			int u = s.top(); s.pop();
			for (int v : g[u]) {
				if (d[v] != -1) continue;
				d[v] = d[u] + 1;
				s.push(v);
			}
		}

		auto it = max_element(d.begin(), d.end());
		return pair<int, int>(it - d.begin(), *it);
	};

	int d1 = dfs(dfs(0, g1).f, g1).s;
	int d2 = dfs(dfs(0, g2).f, g2).s;

	//dbg(d1);
	//dbg(d2);
	cout << max({(d1 + 1) / 2 + (d2 + 1) / 2 + 1, d1, d2}) << endl;

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
