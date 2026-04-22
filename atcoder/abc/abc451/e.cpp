#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n; cin >> n;
	
	vector<vector<int>> D(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			cin >> D[i][j];
			D[j][i] = D[i][j];
		}
	}



	vector<vector<array<int, 2>>> G(n);
	vector<int> Foi(n);
	function<void(int, int)> dfs = [&](int u, int p) {
		Foi[u] = 1;

		vector<int> V(n);
		iota(all(V), 0);
		sort(all(V), [&](int a, int b) { 
			return D[u][a] < D[u][b];
		});

		for (int v : V) if (v != p and !Foi[v] and (p == -1 or D[p][v] == D[p][u] + D[u][v])) {
			G[u].push_back({v, D[u][v]});
			G[v].push_back({u, D[u][v]});
			dfs(v, u);
		}
	};
	dfs(0, -1);

	if (count(all(Foi), 0)) return cout << "No" << endl, 0;

	vector<int> D_(n);
	for (int in = 0; in < n; in++) {
		D_[in] = 0;

		function<void(int, int)> dfs2 = [&](int u, int p) {
			for (auto [v, w] : G[u]) if (v != p) {
				D_[v] = D_[u] + w;
				dfs2(v, u);
			}
		};
		dfs2(in, -1);
		if (D_ != D[in]) return cout << "No" << endl, 0;
	}


	cout << "Yes" << endl;

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

