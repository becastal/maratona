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

void solve() {
	int n, k; cin >> n >> k;
	vector<set<int>> g(n);

	for (int i = 0; i < k; i++) {
		vector<int> vi(n);
		for (int& j : vi) cin >> j;
		for (int j = 2; j < n; j++) {
			g[vi[j-1]-1].emplace(vi[j]-1);
		}
	}
	// esse grafo agora nao pode ter um ciclo.

	vector<int> vis(n, 0), vendo(n, 0);

	function<int(int)> dfs = [&] (int u) {
		vis[u] = 1;
		vendo[u] = 1;

		int res = 0;
		for (int v : g[u]) {
			if (!vis[v]) {
				res |= dfs(v);
			} else if (vendo[v]) {
				return 1;
			}
		}

		vendo[u] = 0;
		return res;
	};

	int res = 0;
	for (int i = 0; i < n and !res; i++) {
		if (!vis[i]) {
			res |= dfs(i);
		}
	}
	cout << (res ? "no" : "yes") << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
