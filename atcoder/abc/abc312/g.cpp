#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	vector<vector<int>> G(n);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);	
		G[v].push_back(u);
	}
	if (n <= 2) return cout << 0 << endl, 0;

	vector<int> P(n), sz(n);
	function<int(int, int)> dfs = [&](int u, int p) {
		sz[u] = 1;
		for (int v : G[u]) if (v != p) {
			sz[u] += dfs(v, P[v] = u);
		}
		return sz[u];
	};
	dfs(0, -1);

	ll ruim = 0;
	for (int u = 0; u < n; u++) {
		ll agr = 0;
		for (int v : G[u]) {
			ll sb = (v == P[u] ? n - sz[u] : sz[v]);	
			agr += sb * sb;
		}
		ruim += (1LL * (n - 1) * (n - 1) - agr) / 2;
	}
	
	cout << 1LL * n * (n - 1) * (n - 2) / 6 - ruim << endl;

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

