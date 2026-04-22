#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<vector<array<int, 2>>> G(n);

	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}

	auto dij = [&](int in) {
		vector<int> D(n, LLONG_MAX); D[in] = 0;
		priority_queue<array<int, 2>> Q; Q.push({0, in});

		while (Q.size()) {
			auto [du, u] = Q.top(); Q.pop();
			if (D[u] != -du) continue;

			for (auto [v, w] : G[u]) if (D[v] > D[u] + w) {
				D[v] = D[u] + w;
				Q.push({-D[v], v});
			}
		}

		return D;
	};

	auto D0 = dij(0);
	if (D0[n-1] == LLONG_MAX) return cout << -1 << endl, 0;

	vector<int> P(k);
	for (int& i : P) {
		cin >> i; i--;
	}
	P.insert(P.begin(), 0);
	P.push_back(n-1);

	int res = 0;
	for (int i = 0; i + 1 < (int)P.size(); i++) {
		auto D = dij(P[i]);
		res += D[P[i+1]];
	}
	cout << res << endl;

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

