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
	vector<vector<pair<int, int>>> g(n);
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}

	vector<ll> druim(n, LINF);

	auto dij1 = [&]() {
		vector<ll> d(n, LINF);
		priority_queue<pair<ll, int>> pq;

		for (int i = 0, u; i < k; i++) {
			cin >> u; u--;
			d[u] = 0;
			pq.emplace(0, u);
		}
	 
		while (pq.size()) {
			auto [ndist, u] = pq.top(); pq.pop();
			if (-ndist > d[u]) continue;
	 
			for (auto [idx, w] : g[u]) if (d[idx] > d[u] + 2 * w) {
				d[idx] = d[u] + 2 * w;
				pq.emplace(-d[idx], idx);
			}
		}

		druim = d;
	};
	dij1();

	auto dij2 = [&](ll mid) {
		vector<ll> d(n, LINF); d[0] = -mid;
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq; pq.emplace(-mid, 0);
	 
		while (pq.size()) {
			auto [ndist, u] = pq.top(); pq.pop();
			if (ndist > d[u]) continue;
			if (ndist > druim[u]) continue;
	 
			for (auto [idx, w] : g[u]) if (d[idx] > d[u] + w) {
				d[idx] = d[u] + w;
				pq.emplace(d[idx], idx);
			}
		}
		return d[n-1] != LINF and d[n-1] <= druim[n-1];
	};


	ll l = 0, r = (ll)1e15+10, res = r;
	while (l <= r) {
		ll mid = l + (r - l) / 2;

		if (dij2(mid)) {
			r = mid-1;	
			res = mid;
		} else {
			l = mid+1;
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
