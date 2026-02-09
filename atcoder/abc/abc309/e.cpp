#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;

	vector<vector<int>> G(n);
	vector<int> P(n, -1);
	for (int i = 1; i < n; i++) {
		cin >> P[i]; P[i]--;
		G[P[i]].push_back(i);
		G[i].push_back(P[i]);
	}

	vector<int> R(n, 0);
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b; a--;
		R[a] = max(R[a], b + 1);	
	}

	function<void(int, int)> dfs = [&](int u, int p) {
		if (p != -1) R[u] = max(R[u], R[p] - 1);
		for (int v : G[u]) if (v != p){
			dfs(v, u);
		}
	};
	dfs(0, -1);

	//for (int i = 0; i < n; i++) {
	//	cout << (i + 1) << ' ' << R[i] << endl;
	//}

	cout << n - count(all(R), 0) << endl;

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

