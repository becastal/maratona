#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m, l; cin >> n >> m >> l;
	int lb, ub; cin >> lb >> ub;

	vector<vector<array<int, 2>>> G(n);
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		G[u].push_back({v, w});
	}

	vector<int> R(n);
	function<void(int, int, int)> dfs = [&](int u, int s, int t) {
		if (!t) {
			R[u] |= (lb <= s and s <= ub);
			return;
		}
		
		for (auto [v, w] : G[u]) {
			dfs(v, s + w, t - 1);	
		}
	};
	dfs(0, 0, l);

	for (int i = 0; i < n; i++) if (R[i]) {
		cout << (i + 1) << ' ';
	}
	cout << endl;

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

