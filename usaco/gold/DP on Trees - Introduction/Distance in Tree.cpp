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
	int n, k; cin >> n >> k;

	vector<vector<int>> G(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	vector<vector<ll>> D(n, vector<ll>(k+1, 0));
	ll res = 0;
	function<void(int, int)> dfs = [&](int u, int p) {
		D[u][0] = 1;

		for (int v : G[u]) if (v != p) {
			dfs(v, u);

			for (int i = 0; i < k; i++) {
				res += D[u][i] * D[v][k-i-1];
			}

			for (int i = 1; i <= k; i++) {
				D[u][i] += D[v][i-1];
			}
		}
	};
	dfs(0, -1);
	cout << res << endl;

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
