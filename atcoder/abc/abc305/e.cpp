#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m, k; cin >> n >> m >> k;

	vector<vector<int>> G(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	priority_queue<array<int, 2>> Q;
	vector<int> D(n);

	vector<array<int, 2>> A(k);
	for (auto& [a, b] : A) {
		cin >> a >> b;
		Q.push({b, a-1});
		D[a-1] = b;
	}

	while (Q.size()) {
		auto [e, u] = Q.top(); Q.pop();
		if (!e) continue;

		for (int v : G[u]) if (e >= D[v] + 1) {
			D[v] = e;	
			Q.push({e-1, v});
		}
	}

	int nn = n - count(all(D), 0);
	vector<int> R(nn);
	for (int i = 0, j = 0; i < n; i++) if (D[i]) {
		R[j++] = i + 1;
	}

	cout << nn << endl;
	for (int i = 0; i < nn; i++) {
		cout << R[i] << " \n"[i==nn-1];
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

