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
	vector<vector<int>> g(n);
	
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> sub(n);
	function<int(int, int)> dfs = [&](int u, int p) {
		sub[u] = 1;
		for (int v : g[u]) if (v != p) {
			sub[u] += dfs(v, u);
		}

		int ok = n - sub[u] <= n / 2;
		for (int v : g[u]) if (v != p) {
			ok &= sub[v] <= n / 2;	
		}
		if (ok) {
			cout << u + 1 << endl;
			exit(0);
		}

		return sub[u];
	};
	dfs(0, -1);

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
