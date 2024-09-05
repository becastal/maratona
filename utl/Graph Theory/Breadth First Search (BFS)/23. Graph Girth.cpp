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

int main()
{
    _;

	int n, m; cin >> n >> m;
	vector<vector<int>> g(n);

	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	auto bfs = [&](int src) {
		queue<int> q; q.push(src);
		vector<int> d(n, -1); d[src] = 0;

		int res = INF;
		while (!q.empty()) {
			int u = q.front(); q.pop();

			for (int v : g[u]) {
				if (d[v] == -1) {
					d[v] = d[u] + 1;
					q.push(v);
				} else if (d[v] >= d[u]) {
					res = min(res, d[v] + d[u] + 1);
				}
			}
		}
		return res;
	};
	
	int res = INF;
	for (int i = 0; i < n; i++) {
		res = min(res, bfs(i));
	}
	cout << (res == INF ? -1 : res) << endl;
    
    return(0);
}
