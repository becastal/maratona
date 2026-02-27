#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> G(n);
	
	for (int i = 1, p; i < n; i++) {
		cin >> p; p--;
		G[i].push_back(p);
		G[p].push_back(i);
	}

	vector<int> A(m), id(n);
	iota(all(id), 0);

	vector<set<int>> S(n);
	for (int i = 0, x; i < m; i++) {
		cin >> x;
		S[n - m + i].insert(x);
	}

	vector<int> R(n, INT_MAX), RR(n, INT_MAX);
	function<int(int, int)> merge = [&](int a, int b) {
		if (S[a].size() < S[b].size()) swap(a, b);
		int res = min(RR[a], RR[b]);

		for (int i : S[b]) {
			auto it = S[a].lower_bound(i);
			if (it != S[a].end()) res = min(res, abs(i - *it));
			if (it != S[a].begin()) res = min(res, abs(i - *prev(it)));
			S[a].insert(i);
		}
		S[b].clear();
		RR[a] = res;

		return a;
	};

	function<int(int, int)> dfs = [&](int u, int p) {
		int c = u;
		for (int v : G[u]) if (v != p) {
			c = merge(c, dfs(v, u));
		}
		R[u] = RR[c];
		return c;
	};
	dfs(0, -1);

	for (int i = 0; i < n - m; i++) {
		cout << R[i] << " \n"[i==n-m-1];
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

