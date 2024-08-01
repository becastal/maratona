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

	// se fosse uma arvore, seria impossivel de escapar. mas, como tem as mesmas constricoes de uma arvore,
	// com n vertices, entao existe 1 ciclo no grafo todo. 
	// so da pra escapar pra sempre se eu chegar no ciclo antes do malandro;

	int t; cin >> t;
	while (t--) {
		int n, a, b; cin >> n >> a >> b; a--, b--;

		vector<vector<int>> g(n);
		for (int i = 0; i < n; i++) {
			int u, v; cin >> u >> v; u--, v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		if (a == b) { cout << "no" << endl; continue; }

		int x = -1;
		auto bfs = [&] (int i) {
			queue<int> q;
			vector<int> d(n, -1), pai(n, -1);
			q.push(i); d[i] = 0;
			
			while (!q.empty()) {
				int u = q.front(); q.pop();
				for (int v : g[u]) {
					if (d[v] == -1) {
						d[v] = d[u] + 1;
						pai[v] = u;
						q.push(v);
					} else if (x == -1 and v != pai[u])
						x = v;
				}
			}
			return d;
		};

		auto dv = bfs(a);
		auto dm = bfs(b);

		if (dv[x] < dm[x])
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
    
    return(0);
}
