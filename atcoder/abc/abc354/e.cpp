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
	vector<int> A(n), B(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i];
	}

	vector<vector<int>> G(1 << n);
	for (int mask = 1; mask < (1 << n); mask++) {
		for (int i = 0; i < n; i++) if (mask >> i & 1) {
			for (int j = i + 1; j < n; j++) if (mask >> j & 1) {
				if (A[i] == A[j] or B[i] == B[j]) {
					int mask_ = mask ^ (1 << i) ^ (1 << j);
					G[mask].push_back(mask_);
				}
			}
		}
	}

	vector<int> Dp((1 << n), -1);
	function<int(int)> dfs = [&](int u) {
		if (Dp[u] != -1) return Dp[u];
		if (G[u].empty()) return Dp[u] = 0;
		
		Dp[u] = 0;
		for (int v : G[u]) {
			Dp[u] |= !dfs(v);	
		}
		return Dp[u];
	};
	cout << (dfs((1 << n) - 1) ? "Takahashi" : "Aoki") << endl;

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

