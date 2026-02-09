#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;

	vector<vector<int>> G(n);
	vector<vector<int>> G_(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G_[v].push_back(u);
	}

	vector<int> R(n, 0);
	function<void(int)> dfs = [&](int u) {
		R[u] = 1;

		for (int v : G_[u]) if (!R[v]) {
			dfs(v);
		}
	};

	int q; cin >> q;
	while (q--) {
		int tp, v; cin >> tp >> v; v--;

		if (tp == 1) {
			if (!R[v]) dfs(v);	
		} else {
			cout << (R[v] ? "Yes" : "No") << endl;
		}
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

