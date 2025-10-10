#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;

	vector<int> In(n, 0);
	vector<vector<pair<int, double>>> g(n);
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		g[u].emplace_back(v, double(w));
		In[v]++;
	}

	auto da = [&](double mid) -> pair<int, vector<int>> {
		auto in = In;
		vector<double> dp(n, +1e9);
		vector<int> pai(n, -1), vis(n, 0);
		dp[0] = 0.0;

		function<void(int)> dfs = [&](int u) {
			vis[u] = 1;

			for (auto [v, w] : g[u]) {
				w -= mid;
				if (dp[v] > dp[u] + w) {
					dp[v] = dp[u] + w;
					pai[v] = u;
				}

				if (--in[v] == 0) dfs(v);
			}
		};

		for (int i = 0; i < n; i++) {
			if (!in[i] and !vis[i]) {
				dfs(i);
			}
		}

		if (dp[n-1] > 0.0) return {0, {}};
		vector<int> res;
		for (int u = n-1; u != -1; u = pai[u]) {
			res.push_back(u);
		}
		reverse(all(res));
		return {1, res};
	};

	vector<int> res;
	double l = 0, r = 100.0;
	for (int i = 0; i < 100; i++) {
		double mid = (l + r) / 2.0;

		auto [ok, res_] = da(mid);
		if (!ok) {
			l = mid;
		} else {
			r = mid;
			res = res_;
		}
	}

	cout << (int)res.size() - 1 << endl;
	for (int i : res) cout << i + 1 << ' '; cout << endl;

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
