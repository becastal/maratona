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

	vector<int> a(n);
	for (int& i : a) cin >> i;

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> d(n);
	function<void(int, int)> dfs = [&](int u, int p) {
		for (int v : g[u]) {
			if (v == p) continue;
			d[v] = d[u] + 1;
			dfs(v, u);
		}
	};
	
	vector<vector<int>> dp(n, vector<int>(n, 0));
	for (int u = 0; u < n; u++) {

	}

	d[0] = 0;
	dfs(0, -1);

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
