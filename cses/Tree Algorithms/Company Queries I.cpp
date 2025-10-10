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
	int n, q; cin >> n >> q;
	int nn = __lg(n) + 1;

	vector<vector<int>> pai(n, vector<int>(nn, -1)), g(n);
	for (int i = 1, pi; i < n; i++) {
		cin >> pi; pi--;
		g[pi].push_back(i);
		g[i].push_back(pi);
	}

	function<void(int, int)> dfs = [&](int u, int p) {
		pai[u][0] = p;
		for (int v : g[u]) {
			if (v == p) continue;
			dfs(v, u);
		}
	};
	dfs(0, -1);

	for (int j = 1; j < nn; j++) {
		for (int u = 0; u < n; u++) {
			int pu = pai[u][j-1];
			pai[u][j] = (pu == -1 ? -1 : pai[pu][j-1]);
		}
	}

	while (q--) {
		int u, k; cin >> u >> k; u--;
		for (int j = 0; j < nn and u != -1; j++) {
			if (k & (1 << j)) {
				u = pai[u][j];
			}
		}
		cout << u + (u >= 0) << endl;
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
