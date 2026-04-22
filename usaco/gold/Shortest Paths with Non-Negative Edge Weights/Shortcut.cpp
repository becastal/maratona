#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

/*

precisa de uma dp em dag.
preco total - preco calc[u] nessa dag + preco quanto custaria se botasse a aresta aqui
calcuma isso pra todo u

*/

int solve() {
	int n, m, t; cin >> n >> m >> t;
	vector<int> C(n);
	for (int& i : C) {
		cin >> i;
	}
	
	vector<vector<array<int, 2>>> G(n);
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}

	vector<int> D(n, LLONG_MAX); D[0] = 0;
	priotity_queue<array<int, 2>> Pq; Pq.push({0, 0});

	while (Pq.size()) {
		auto [du, u] = Pq.top(); Pq.pop();
		if (-du != D[u]) continue;

		for (auto [v, w] : G[u]) if (D[v] > D[u] + w) {
			D[v] = D[u] + w;
			Pq.push({-D[v], v});
		}
	}

	vector<array<int, 2>> Pai(n, {LLONG_MAX, -1});
	for (int u = 0; u < n; u++) {
		for (auto [v, w] : G[u]) if (D[u] + w == D[v]) {
			Pai[v] = min(Pai[v], array<int, 2>{u, w});
		}
	}

	vector<int> In(n);
	queue<int> Q;
	for (int u = 0; u < n; u++) {
		In[Pai[u]]++;
	}
	for (int u = 0; u < n; u++) if (!In[u]) {
		Q.push(u);	
	}

	vector<int> Calc(n);
	while (Q.size()) {
		int u = Q.front(); Q.pop();
		auto [v, w] = Pai[u];
		
		if (--In[v] == 0) {
			Q.push(v);
		}
	}

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

