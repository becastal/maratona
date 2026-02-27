#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int mod = 1e9+7;
signed solve() {
	int n; cin >> n;
	vector<int> C(n);
	for (int& i : C) {
		cin >> i;
	}

	int m; cin >> m;
	vector<vector<int>> G(n);

	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b; a--, b--;
		G[a].push_back(b);
	}

	stack<int> s;
	vector<int> vis(n), id(n), comp(n, -1);
	function<int(int, int&)> dfs = [&](int i, int& t) {
		int lo = id[i] = t++;
		s.push(i);
		vis[i] = 2;

		for (int j : G[i]) {
			if (!vis[j]) lo = min(lo, dfs(j, t));
			else if (vis[j] == 2) lo = min(lo, id[j]);
		}

		if (lo == id[i]) while (1) {
			int u = s.top(); s.pop();	
			vis[u] = 1, comp[u] = i;
			if (u == i) break;
		}

		return lo;
	};

	int t = 0;
	for (int i = 0; i < n; i++) if (!vis[i]) {
		dfs(i, t);
	}

	vector<int> CC(n, LLONG_MAX), CCC(n, 0);
	for (int i = 0; i < n; i++) {
		if (C[i] < CC[comp[i]]) {
			CC[comp[i]] = C[i];
			CCC[comp[i]] = 1;
		} else if (C[i] == CC[comp[i]]) {
			CCC[comp[i]]++;
		}
	}

	int resa = 0, resb = 1;
	for (int i = 0; i < n; i++) if (CC[i] != LLONG_MAX) {
		resa += CC[i];	
		resb = (resb * CCC[i]) % mod;
	}
	cout << resa << ' ' << resb << endl;

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
