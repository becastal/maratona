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
	int n, a, b; cin >> n >> a >> b;
	vector<int> P(n);

	map<int, int> M;
	for (int i = 0; i < n; i++) {
		cin >> P[i];
		M[P[i]] = i;
	}

	vector<vector<int>> g(n);
	for (int i = 0; i < n; i++) {
		if (M.count(a - P[i])) {
			g[i].push_back(M[a - P[i]]);
		}
		if (M.count(b - P[i])) {
			g[i].push_back(M[b - P[i]]);
		}
	}

	vector<int> vis(n, 0), cor(n, 0);

	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;

		int oka = 1, okb = 1;
		vector<int> comp;
		function<void(int)> dfs = [&](int u) {
			comp.push_back(u);
			vis[u] = 1;

			if (!M.count(a - P[u])) oka = 0;
			if (!M.count(b - P[u])) okb = 0;
			for (int v : g[u]) if (!vis[v]) {
				dfs(v);
			}
		};
		dfs(i);
		if (!oka and !okb) return cout << "NO" << endl, 0;
		for (int u : comp) cor[u] = oka ? 0 : 1;
	}

	cout << "YES" << endl;
	for (int i : cor) cout << i << ' '; cout << endl;

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
