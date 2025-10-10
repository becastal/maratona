#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n; cin >> n;

	vector<vector<int>> G(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int m = __lg(n) + 1;
	vector<int> D(n, 0);
	vector<vector<int>> pai(n, vector<int>(m, 0));
	function<void(int, int)> dfs = [&](int u, int p) {
		for (int v : G[u]) if (v != p) {
			D[v] = D[u] + 1;
			dfs(v, pai[v][0] = u);
		}
	};
	dfs(0, -1);

	for (int j = 1; j < m; j++) {
		for (int i = 0; i < n; i++) {
			pai[i][j] = pai[pai[i][j-1]][j-1];	
		}
	}

	auto kth = [&](int u, int k) {
		for (int i = 0; i < m; i++) if (k >> i & 1) {
			u = pai[u][i];
		}
		return u;
	};

	auto lca = [&](int a, int b) {
		if (D[b] > D[a]) swap(a, b);

		a = kth(a, D[a] - D[b]);
		if (a == b) return a;

		for (int i = m-1; i >= 0; i--) {
			if (pai[a][i] != pai[b][i]) {
				a = pai[a][i];
				b = pai[b][i];
			}
		}
		return pai[a][0];
	};

	int q; cin >> q;
	while (q--) {
		int u, v, k; cin >> u >> v >> k; u--, v--;
		int w = lca(u, v);

		int a = min(D[u] - D[w], k);
		k -= a;

		if (!k) {
			cout << kth(u, a) + 1 << endl;
			continue;
		}

		int b = max(0, (D[v] - D[w]) - k);
		cout << kth(v, b) + 1 << endl;	
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
