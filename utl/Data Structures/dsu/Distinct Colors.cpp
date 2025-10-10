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

	vector<int> A(n), id(n);
	vector<set<int>> S(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		S[i].insert(A[i]);
		id[i] = i;
	}

	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	function<int(int, int)> merge = [&](int a, int b) {
		if (S[a].size() < S[b].size()) swap(a, b);
		for (int i : S[b]) S[a].insert(i);
		S[b].clear();
		return a;
	};

	vector<int> R(n);
	function<int(int, int)> dfs = [&](int u, int p) {
		int c = u;
		for (int v : G[u]) if (v != p) {
			c = merge(c, dfs(v, u));
		}
		R[u] = S[c].size();
		return c;
	};

	dfs(0, -1);
	for (int i : R) cout << i << ' '; cout << endl;

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

