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
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	vector<vector<int>> G(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	map<int, int> F, FF;
	auto add = [&](int u) {
		if (--FF[F[u]] == 0) FF.erase(F[u]);
		FF[++F[u]]++;	
	};
	auto rem = [&](int u) {
		if (--FF[F[u]] == 0) FF.erase(F[u]);
		FF[--F[u]]++;	
	};
	auto query = [&]() {
		return FF.rbegin()->first > 1;
	};

	vector<int> Res(n);
	function<void(int, int)> dfs = [&](int u, int p) {
		add(A[u]);
		Res[u] = query();
		for (int v : G[u]) if (v != p) {
			dfs(v, u);
		}
		rem(A[u]);
	};
	dfs(0, -1);

	for (int i : Res) {
		cout << (i ? "Yes" : "No") << endl;
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
