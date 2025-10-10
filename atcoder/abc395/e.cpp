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

	int n, m, x; cin >> n >> m >> x;

	vector<vector<vector<int>>> g(2, vector<vector<int>>(n));
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;	
		g[0][u].push_back(v);
		g[1][v].push_back(u);
	}

	vector<vector<ll>> d(2, vector<ll>(n, LINF));
	auto bfs = [&]() {
		priority_queue<tuple<ll, int, int>> q; q.emplace(0, 0, 0);
		d[0][0] = 0;

		while (q.size()) {
			auto [du, u, agr] = q.top(); q.pop();
			du = -du;
			if (d[agr][u] != du) continue;
			
			for (int v : g[agr][u]) {
				if (d[agr][v] <= du + 1) continue;
				d[agr][v] = du + 1;
				q.emplace(-d[agr][v], v, agr);
			}

			if (du + x < d[agr^1][u]) {
				d[agr^1][u] = du + x;
				q.emplace(-d[agr^1][u], u, agr^1);
			}
		}
	};
	bfs();

	cout << min(d[0][n-1], d[1][n-1]) << endl;
    
    return(0);
}
