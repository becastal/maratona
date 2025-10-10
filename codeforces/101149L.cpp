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
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	vector<vector<int>> G(n+1), G_(n+1);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		G[u].push_back(v);
		G_[v].push_back(u);
	}

	auto bfs = [&n](int u, vector<vector<int>>& G) {
		vector<int> D(n+1, INF); D[u] = 0;
		queue<int> Q; Q.push(u);

		while (Q.size()) {
			int u = Q.front(); Q.pop();

			for (int v : G[u]) if (D[v] == INF) {
				D[v] = D[u] + 1;
				Q.push(v);
			}
		}
		return D;
	};

	auto D0 = bfs(0, G);
	auto Da = bfs(a, G_);
	auto Db = bfs(b, G_);

	int res = INF;
	for (int u = 0; u <= n; u++) {
		res = min(res, D0[u] + Da[u] + Db[u]);
	}
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

