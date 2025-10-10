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

void solve() {
	int n, a, b;
	cin >> n >> a >> b; a--, b--;

	vector<vector<int>> g(n), res(n+1);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}


	vector<int> d(n, 0);
	function<void(int, int)> dfs = [&](int u, int p) {
		for (int v : g[u]) {
			if (v == p) continue;
			d[v] = d[u] + 1;
			res[d[v]].push_back(v+1);
			dfs(v, u);
		}
	};
	dfs(b, -1);

	for (int i = n; i >= 0; i--) {
		for (int j : res[i]) {
			cout << j << ' ';
		}
	}
	cout << b+1 << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
