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

	vector<vector<int>> G(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { 
			char c; cin >> c;
			G[i][j] = (c == '1');
		}
	}

	vector<vector<int>> Vis(n, vector<int>(n));
	for (int in = 0; in < n; in++) {
		function<void(int)> dfs = [&](int u) {
			Vis[in][u] = 1;
			for (int v = 0; v < n; v++) if (!Vis[in][v] and G[u][v]) {
				dfs(v);
			}
		};
		dfs(in);
	}

	double res = 0;
	for (int u = 0; u < n; u++) {
		int cont = 0;
		for (int in = 0; in < n; in++) {
			cont += Vis[in][u];
		}
		res += 1.0 / cont;
	}

	cout << fixed << setprecision(10);
	cout << res << endl;

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

