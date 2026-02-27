#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, q; cin >> n >> q;
	vector<int> V(n);

	vector<vector<int>> G(n);
	for (int& i : V) cin >> i;
	for (int i = 1, p; i < n; i++) {
		cin >> p; p--;
		G[p].push_back(i);
	}

	function<void(int)> dfs = [&](int u) {
		for (int v : G[u]) {
			V[v] += V[u];
			dfs(v);
		}
	};
	dfs(0);

	while (q--) {
		int u; cin >> u; u--;
		cout << V[u] << endl;
	}

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

