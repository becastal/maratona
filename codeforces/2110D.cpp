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
	vector<int> B(n);
	for (int& i : B) {
		cin >> i;
	}

	vector<vector<array<int, 2>>> G(n);
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		G[u].push_back({v, w});
	}

	function<int(int)> da = [&](int lim) {
		vector<int> In(n);
		for (int u = 0; u < n; u++) {
			for (auto [v, w] : G[u]) if (w <= lim) {
				In[v]++;
			}
		}

		queue<int> Q;
		for (int u = 0; u < n; u++) if (!In[u]) {
			Q.push(u);
		}

		vector<int> Dp(n, LLONG_MIN);
		Dp[0] = min(lim, B[0]);

		while (Q.size()) {
			int u = Q.front(); Q.pop();
			
			for (auto [v, w] : G[u]) if (w <= lim) {
				if (Dp[u] >= w) {
					Dp[v] = min(lim, max(Dp[v], Dp[u] + B[v]));
				}
				
				if (--In[v] == 0) {
					Q.push(v);
				}
			}
		}

		return Dp[n-1] != LLONG_MIN;
	};

	int l = 0, r = (int)1e9 + 10, res = -1;
	while (l <= r) {
		int mid = l + (r - l) / 2;

		if (da(mid)) {
			r = mid - 1;
			res = mid;
		} else {
			l = mid + 1;
		}
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

