#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<vector<int>> G(n);

	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	function<void(int, vector<int>&)> dfs = [&](int u, vector<int>& D) {
		for (int v : G[u]) if (D[v] == -1) {
			D[v] = D[u] + 1;
			dfs(v, D);
		}
	};

	vector<int> D1(n, -1), Dn(n, -1);
	D1[0] = Dn[n-1] = 0;

	dfs(0, D1);
	dfs(n-1, Dn);
	
	vector<int> C(2, 0);
	for (int u = 0; u < n; u++) {
		C[D1[u] <= Dn[u]]++;
	}

	cout << (C[1] > C[0] ? "Fennec" : "Snuke") << endl;

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

