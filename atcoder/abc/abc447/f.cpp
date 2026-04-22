#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n; cin >> n;

	vector<vector<int>> G(n);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	vector<vector<int>> Dag(n), Dag_(n);
	vector<int> In(n), In_(n);
	for (int u = 0; u < n; u++) {
		for (int v : G[u]) if (u < v and G[u].size() > 2) {
			Dag[u].push_back(v);
			In[v]++;

			Dag_[u].push_back(v);
			In_[u]++;
		}
	}
	
	vector<int> D(n), Vis(n);
	function<void(int)> dfs = [&](int u) {
		Vis[u] = 1;
		for (int v : Dag[u]) {
			D[v] = max(D[v], D[u] + 1);
			if (!--In[v]) {
				dfs(v);
			}
		}
	};

	vector<int> D_(n), Vis_(n);
	function<void(int)> dfs_ = [&](int u) {
		Vis_[u] = 1;
		for (int v : Dag_[u]) {
			D_[v] = max(D_[v], D_[u] + 1);
			if (!--In_[v]) {
				dfs_(v);
			}
		}
	};

	for (int u = 0; u < n; u++) if (!Vis[u] and !In[u]) {
		dfs(u);	
	}
	for (int u = 0; u < n; u++) if (!Vis_[u] and !In_[u]) {
		dfs_(u);	
	}

	int res = LLONG_MIN;
	for (int u = 0; u < n; u++) {
		res = max(res, D[u] + D_[u]);
	}
	cout << res << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

