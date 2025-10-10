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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("piggybac");

	int b, e, p; cin >> b >> e >> p;
	int n, m; cin >> n >> m;

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	auto bfs = [&] (int in, int peso) {
		vector<int> d(n, INF);
		d[in] = 0;

		queue<int> q;
		q.push(in);

		while (q.size()) {
			int u = q.front(); q.pop();

			for (int v : g[u]) {
				if (d[v] != INF) continue;
				d[v] = d[u] + peso;
				q.push(v);
			}
		}

		return d;
	};

	auto B = bfs(0, b);
	auto E = bfs(1, e);
	auto P = bfs(n-1, p);

	int res = B[n-1] + E[n-1];
	for (int i = 0; i < n; i++) {
		res = min(res, B[i] + E[i] + P[i]);
	}
	cout << res << endl;

    return(0);
}
