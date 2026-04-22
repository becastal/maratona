#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, k; cin >> n >> k; k--;
	vector<vector<int>> G(n);

	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);	
		G[v].push_back(u);	
	}

	vector<int> D(n, LLONG_MAX);
	queue<int> Q;
	for (int u = 0; u < n; u++) if (G[u].size() == 1) {
		Q.push(u);	
		D[u] = 0;
	}

	while (Q.size()) {
		int u = Q.front(); Q.pop();

		for (int v : G[u]) if (D[v] == LLONG_MAX) {
			D[v] = D[u] + 1;
			Q.push(v);
		}
	}

	int res = 0;
	function<void(int, int, int)> dfs = [&](int u, int d, int p) {
		if (D[u] <= d) {
			res++;
			return;
		}

		for (int v : G[u]) if (v != p) {
			dfs(v, d + 1, u);
		}
	};
	dfs(k, 0, -1);
	cout << res << endl;

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

signed main()
{
    _;
	setIO("atlarge");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

