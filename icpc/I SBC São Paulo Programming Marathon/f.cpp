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
	vector<int> a(n), d(n, 0), sub(n, 0);
	for (int& i : a) cin >> i, i = (i > k);

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);	
		g[v].push_back(u);	
	}

	int mx = 0;
	function<int(int, int)> dfs = [&](int u, int p) {
		int s = 0;
		for (int v : g[u]) {
			if (v == p) continue;
			d[v] = d[u] + 1;
			if (a[v]) mx = max(mx, d[v]);
			s += dfs(v, u);
		}
		return sub[u] = s + a[u];
	};
	dfs(0, -1);

	int m = (n - count(sub.begin(), sub.end(), 0) - 1);
	cout << max(0, 2 * m - mx) << endl;

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
