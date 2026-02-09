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
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
	}

	vector<int> cic(11, 0);
	cic[0] = 1;
	function<int(int, int)> dfs = [&](int u, int c) {
		if (!c) {
			if (!u) return 1;
			return 0;
		}

		if (!u and c != 10) {
			int t = 10 - c;
			for (int i = t; i <= 10; i++) {
				cic[i] |= cic[i-t];
			}
			return cic[10];
		}
		
		for (int v : G[u]) {
			if (dfs(v, c-1)) return 1;
		}
		return 0;
	};
	cout << (dfs(0, 10) ? "Yes" : "No") << endl;

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

