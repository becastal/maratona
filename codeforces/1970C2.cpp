#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, t; cin >> n >> t;

	vector<vector<int>> G(n);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);	
		G[v].push_back(u);	
	}

	vector<int> dp(n);
	function<int(int, int)> dfs = [&](int u, int p) {
		for (int v : G[u]) if (v != p) {
			if (!dfs(v, u)) return 1;
		}
		return 0;
	};

	int in; cin >> in; in--;
	cout << (dfs(in, -1) ? "Ron" : "Hermione") << endl;;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

