#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const int MAX = 2e5+10;
vector<int> g[MAX];

vector<int> topo_sort(int n) {
	vector<int> ret(n,-1), vis(n,0);

	int pos = n-1, dag = 1;
	function<void(int)> dfs = [&](int v) {
		vis[v] = 1;
		for (auto u : g[v]) {
			if (vis[u] == 1) dag = 0;
			else if (!vis[u]) dfs(u);
		}
		ret[pos--] = v, vis[v] = 2;
	};

	for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);

	if (!dag) ret.clear();
	return ret;
}

int solve() {
	int n; cin >> n;

	//vector<vector<array<int, 2>>> G(n);
	for (int i = 0, u, v, x, y; i < n-1; i++) {
		cin >> u >> v >> x >> y; u--, v--;
		if (x > y) g[v].push_back(u);
		if (x < y) g[u].push_back(v);
		//G[u].push_back({v, x > y});
		//G[v].push_back({u, x < y});
	}

	//vector<int> P(n);
	//function<void(int, int)> dfs = [&](int u, int p) {
	//	for (auto [v, c] : G[u]) if (p != v) {
	//		P[v] = P[u] + (c ? +1 : -1);
	//		dfs(v, u);
	//	}
	//};
	//dfs(0, -1);

	//vector<int> P_(P);
	//sort(all(P_));
	//P_.erase(unique(all(P_)), P_.end());
	//for (int& i : P) i = lower_bound(all(P_), i) - P_.begin() + 1;
	//for (int i : P) cout << i << ' '; cout << endl;

	vector<int> R = topo_sort(n), P(n);
	for (int i = 0; i < n; i++) {
		P[R[i]] = i;
	}

	for (int i = 0; i < n; i++) {
		cout << P[i] + 1 << " \n"[i==n-1];	
		g[i].clear();
	}

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

