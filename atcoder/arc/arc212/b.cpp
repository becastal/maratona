#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;
	
	int in, out, pre;
	vector<vector<array<int, 2>>> G(n);
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		if (!i) in = u, out = v, pre = w;
		else {
			G[u].push_back({v, w});
			//G[v].push_back({u, w});
		}
	}

	vector<ll> D(n, LLONG_MAX); D[out] = 0;
	priority_queue<pair<ll, int>> pq; pq.emplace(0, out);

	while (pq.size()) {
		auto [ndist, u] = pq.top(); pq.pop();
		if (-ndist > D[u]) continue;

		for (auto [idx, w] : G[u]) if (D[idx] > D[u] + w) {
			D[idx] = D[u] + w;
			pq.emplace(-D[idx], idx);
		}
	}

	if (D[in] == LLONG_MAX) return cout << -1 << endl, 0;
	cout << pre + D[in] << endl;

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

