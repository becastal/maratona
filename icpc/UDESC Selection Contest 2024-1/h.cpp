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
	int n, m, k; cin >> n >> m >> k;

	int mxw = 0;
	vector<vector<pair<int, int>>> g(n);
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
		mxw = max(mxw, w);
	}

	auto bfs = [&](int mid) {
		vector<int> d(n, INF); d[0] = 0;
		deque<int> q; q.push_front(0);

		while (q.size()) {
			int u = q.front(); q.pop_front();

			for (auto [v, w] : g[u]) {
				w = (w > mid);
				if (d[u] + w >= d[v]) continue;

				d[v] = d[u] + w;
				if (w) q.push_back(v);
				else q.push_front(v);
			}
		}

		return d[n-1] <= k;
	};

	int l = 0, r = mxw, res = r;
	while (l <= r) {
		int mid = l + (r - l) / 2;

		if (bfs(mid)) {
			res = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << res << endl;

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
