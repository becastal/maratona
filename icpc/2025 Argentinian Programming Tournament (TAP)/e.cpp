#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> A(n, 0);
	for (int i = 1; i < n; i++) {
		cin >> A[i];
	}

	vector<vector<int>> G(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	array<ll, 2> res = {0, 0};
	vector<ll> D(n+1, 0);
	int mxd = 0;
	function<void(int, int, int)> dfs = [&](int u, int p, int d) {
		D[d] += A[u], mxd = max(mxd, d);
		for (int v : G[u]) if (v != p) {
			dfs(v, u, d + 1);
		}

		if (d == 1) {
			for (int i = 0; i <= mxd; i++) {
				res = max(res, {D[i], -i});	
				D[i] = 0;
			}
			mxd = 0;
		}
	};
	dfs(0, -1, 0);

	cout << res[0] << ' ' << -res[1] << endl;

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

