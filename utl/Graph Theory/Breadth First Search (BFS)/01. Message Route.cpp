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
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b; a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector<int> d(n, -1), pai(n, -1), res;
	auto bfs = [&]() {
		queue<int> q; q.push(0);
		d[0] = 0;

		while (!q.empty()) {
			int u = q.front(); q.pop();

			for (int v : g[u]) {
				if (d[v] != -1) continue;

				d[v] = d[u] + 1;
				pai[v] = u;
				q.push(v);
			}
		}
	};
	bfs();

	if (d[n-1] == -1) return cout << "IMPOSSIBLE" << endl, 0;

	int k = n - 1;
	while (pai[k] != -1) {
		res.push_back(k + 1);
		k = pai[k];
	}
	res.push_back(1);
	reverse(res.begin(), res.end());
	cout << (int)res.size() << endl;
	for (int i : res) cout << i << ' ';
	cout << endl;
    
    return(0);
}
