#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;
	
	vector<tuple<int, int, int>> ar(m);

	vector<vector<int>> g(n), g_(n);
	vector<int> vis(n, 0), vis_(n, 0), cic(n, 0);
	for (auto& [u, v, w] : ar) {
		cin >> u >> v >> w, u--, v--, w = -w;
		g[u].push_back(v);	
		g_[v].push_back(u);	
	}

	function<void(int, vector<int>&, vector<vector<int>>&)> dfs = 
			[&](int u, vector<int>& vi, vector<vector<int>>& ga) {
		vi[u] = 1;

		for (int v : ga[u]) {
			if (vi[v]) continue;
			dfs(v, vi, ga);
		}
	};
	dfs(0, vis, g);
	dfs(n-1, vis_, g_);

	auto bellman = [&](int in) {
		vector<ll> d(n, LINF), cic(n, 0); d[in] = 0;
		for (int i = 0; i <= n; i++) {
			for (auto [u, v, w] : ar) {
				if (d[u] != LINF and d[u] + w < d[v]) {
					if (i < n) d[v] = d[u] + w;
					else cic[v] = 1;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			if (cic[i]) {
				dfs(i, cic, g);
			}
		}
	};

	bellman();

	//for (int i : vis) cout << i << ' '; cout << endl;
	//for (int i : vis_) cout << i << ' '; cout << endl;
	//for (int i : cic) cout << i << ' '; cout << endl;
	for (int i = 0; i < n; i++) if (vis[i] and vis_[i] and cic[i]) return cout << -1 << endl, 0;
	cout << -d[n-1] << endl;


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
