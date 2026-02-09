#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> C(n);
	for (int& i : C) cin >> i, i--;

	vector<vector<int>> G(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	vector<int> R(k), D(n, -1); D[0] = 0;
	queue<int> Q; Q.push(0);
	while (Q.size()) {
		int u = Q.front(); Q.pop();

		for (int v : G[u]) if (D[v] == -1) {
			D[v] = D[u] + 1;
			Q.push(v);
		}
	}

	for (int i = 0; i < n; i++) {
		R[C[i]] = max(R[C[i]], D[i]);
	}

	for (int i = 0; i < k; i++) {
		cout << R[i] << " \n"[i == k-1];
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

