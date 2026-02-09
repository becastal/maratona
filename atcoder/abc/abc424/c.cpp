#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	vector<vector<int>> G(n+1);
	for (int i = 1, a, b; i <= n; i++) {
		cin >> a >> b;
		G[a].push_back(i);
		G[b].push_back(i);
	}

	vector<int> vis(n+1, 0);
	vis[0] = 1;
	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;	

		for (int v : G[u]) if (!vis[v]) {
			dfs(v);
		}
	};
	dfs(0);

	cout << count(all(vis), 1) - 1 << endl;

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
