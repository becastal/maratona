#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int mod = 998244353;
int solve() {
	int n; cin >> n;

	vector<vector<int>> G(n);
	for (int i = 1, p; i < n; i++) {
		cin >> p; p--;
		G[p].push_back(i);
	}

	vector<int> D(n);
	vector<vector<int>> U(n);
	function<void(int)> dfs = [&](int u) {
		U[D[u]].push_back(u);
		for (int v : G[u]) {
			D[v] = D[u] + 1;
			dfs(v);
		}
	};
	dfs(0);

	vector<int> Dp(n), Dp_(n + 1);
	Dp[0] = 1;

	auto add = [&](int& a, int b) {
		a += b;
		if (a >= mod) {
			a -= mod;
		}
		if (a < 0) {
			a += mod;
		}
	};

	for (int d = 0; d < n; d++) {
		for (int u : U[d]) {
			add(Dp[u], Dp_[d]);
			add(Dp_[d+1], Dp[u]);

			if (u) for (int v : G[u]) {
				add(Dp[v], -Dp[u]);
			}
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		//cout << i << ": " << Dp[i] << endl;
		add(res, Dp[i]);
	}
	cout << res << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

