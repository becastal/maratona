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
	for (int i = 0, nn; i < n; i++) {
		cin >> nn;
		for (int j = 0, v; j < nn; j++) { 
			cin >> v; v--;
			G[i].push_back(v);
			//cout << i + 1 << ' ' << v + 1 << endl;
		}
	}

	vector<int> vis(n);
	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;
		for (int v : G[u]) if (!vis[v]) { 
			dfs(v);
		}
	};
	dfs(0);

	int nn = count(all(vis), 1);
	vector<int> B;
	for (int i = 0; i < n; i++) if (vis[i]) {
		B.push_back(i);
	}

	auto topo_sort = [](int n, vector<vector<int>>& G) {
		vector<int> ret(n,-1), vis(n,0);
		
		int pos = n-1, dag = 1;
		function<void(int)> dfs = [&](int v) {
			vis[v] = 1;
			for (auto u : G[v]) {
				if (vis[u] == 1) dag = 0;
				else if (!vis[u]) dfs(u);
			}
			ret[pos--] = v, vis[v] = 2;
		};

		for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);

		if (!dag) ret.clear();	
		return ret;
	};

	vector<vector<int>> G_(nn);
	for (int i = 0, j = 0; i < n; i++) if (vis[i]) {
		for (int v : G[i]) if (vis[v]) {
			G_[lower_bound(all(B), v) - B.begin()].push_back(j);
		}
		j++;
	}

	auto V = topo_sort(nn, G_);	
	erase(V, 0);
	for (int i = 0; i < nn - 1; i++){ 
		cout << B[V[i]] + 1 << " \n"[i==nn-2];
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

