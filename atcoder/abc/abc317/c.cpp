#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;

	vector<vector<int>> D(n, vector<int>(n, -1));
	for (int i = 0, a, b, w; i < m; i++) {
		cin >> a >> b >> w; a--, b--;
		D[a][b] = D[b][a] = w;
	}

	ll res = LLONG_MIN;
	vector<int> vis(n, 0);
	function<void(int, ll)> dfs = [&](int u, ll s) {
		vis[u] = 1;
		res = max(res, s);

		for (int v = 0; v < n; v++) if (!vis[v] and D[u][v] != -1) {
			dfs(v, s + D[u][v]);

		}
		
		vis[u] = 0;
	};

	for (int i = 0; i < n; i++) {
		dfs(i, 0);
	}
	cout << res << endl;

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

