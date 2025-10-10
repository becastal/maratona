#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n, m, d, mn = INF, mx = -INF; cin >> n >> m >> d;

	vector<vector<pair<int, int>>> g(n);
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		g[u].emplace_back(v, w);
		//g[v].emplace_back(u, w);
		mn = min(mn, w);
		mx = max(mx, w);
	}

	auto bfs = [&](int mid) -> pair<int, vector<int>> {
		vector<int> dis(n, INF), pai(n, -1); dis[0] = 0;
		queue<int> q; q.emplace(0);

		while (q.size()) {
			int u = q.front(); q.pop();
			for (auto [v, w] : g[u]) {
				if (dis[v] != INF or w > mid) continue;
				dis[v] = dis[u] + 1;
				pai[v] = u;
				q.emplace(v);
			}
		}
		if (dis[n-1] > d) return {0, {}};

		vector<int> res;
		for (int u = n-1; u != -1; u = pai[u]) {
			res.push_back(u);
		}
		reverse(res.begin(), res.end());
		return {1, res};
	};

	int l = mn, r = mx;
	vector<int> res = {};
	while (l <= r) {
		int mid = l + (r - l) / 2;	

		auto [da, res_] = bfs(mid);
		if (da) {
			r = mid - 1;	
			res = res_;
		} else {
			l = mid + 1;
		}
	};

	if (res.empty()) return cout << -1 << endl, 0;

	cout << (int)res.size()-1 << endl;
	for (int i : res) cout << i+1 << ' '; cout << endl;

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
