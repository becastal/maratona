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
	int n, k; cin >> n >> k;

	vector<int> c(n), cont(n, 0);
	for (int& i : c) cin >> i;

	for (int i = 0, pi; i < k; i++) {
		cin >> pi; pi--;
		c[pi] = 0;
	}


	vector<vector<int>> g(n);
	for (int i = 0, m; i < n; i++) {
		cin >> m;
		for (int j = 0, e; j < m; j++) {
			cin >> e; e--;
			if (c[i]) g[i].push_back(e);
			cont[e]++;
		}
	}

	vector<ll> res(n), vis(n, 0);
	function<int(int)> dfs = [&](int u) {
		vis[u] = 1;
		ll agr = 0;	

		for (int v : g[u]) {
			if (!vis[v]) {
				agr += dfs(v);
			} else agr += res[v];
		}

		return res[u] = min((g[u].empty() ? LINF : agr), (ll)c[u]);
	};

	for (int i = 0; i < n; i++) {
		if (!vis[i]) dfs(i);
	}

	for (int i : res) cout << i << ' '; cout << endl;

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
