#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> A(n);

	vector<map<int, ll>> F(n), SF(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		F[i][A[i]] = 1;
		SF[i][1] = A[i];
	}

	vector<vector<int>> G(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	function<int(int, int)> merge = [&](int a, int b) {
		if (F[a].size() < F[b].size()) swap(a, b);

		for (auto [v, f] : F[b]) {
			if (F[a].count(v) and SF[a].count(F[a][v])) SF[a][F[a][v]] -= a;
			SF[a][F[a][v] += f] += v;
		}
		F[b].clear(), SF[b].clear();

		return a;
	};

	vector<ll> R(n);
	function<int(int, int)> dfs = [&](int u, int p) {
		int s = u;
		for (int v : G[u]) if (v != p) {
			s = merge(s, dfs(v, u));
		}
		R[u] = SF[s].rbegin()->second;
		return s;
	};
	dfs(0, -1);

	for (int i = 0; i < n; i++) {
		cout << R[i] << " \n"[i==n-1];
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

