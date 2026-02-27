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

	vector<array<int, 3>> A(n);
	for (auto& [a, b, c] : A) {
		cin >> a >> b >> c;
	}

	auto inter = [&](int i, int j) {
		auto [ai, bi, ci] = A[i];
		auto [aj, bj, cj] = A[j];

		long long aa = ai - aj;
		long long bb = bi - bj;
		long long cc = ci - cj;

		if (aa == 0) {
			return (bb != 0) or (bb == 0 and cc == 0);
		}
		return (bb * bb - 4LL * aa * cc) >= 0;
	};

	vector<vector<int>> G(n), G_(n);
	for (int i = 0; i < n; i++) {
		auto [ai, bi, ci] = A[i];
		for (int j = i + 1; j < n; j++) if (!inter(i, j)) {
			auto [aj, bj, cj] = A[j];

			if ((ai > aj) or (ai == aj and ci > cj)) {
				G[i].push_back(j);
				G_[j].push_back(i);
			} else {
				G[j].push_back(i);
				G_[i].push_back(j);
			}
		}
	}

	vector<int> dp(n, -1), dp_(n, -1);
	function<int(int)> dfs = [&](int u) -> int {
		if (dp[u] != -1) return dp[u];
		int res = 1;
		for (int v : G[u]) {
			res = max(res, 1 + dfs(v));
		}
		return dp[u] = res;
	};
	function<int(int)> dfs_ = [&](int u) -> int {
		if (dp_[u] != -1) return dp_[u];
		int res = 1;
		for (int v : G_[u]) {
			res = max(res, 1 + dfs_(v));
		}
		return dp_[u] = res;
	};
	for (int i = 0; i < n; i++) {
		cout << dfs(i) + dfs_(i) - 1 << " \n"[i==n-1];
	}

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

