#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m, l, s = 0, minodd = LLONG_MAX; cin >> n >> m >> l;

	vector<int> A(l);
	for (int& i : A) {
		cin >> i;
		s += i;
		if (i & 1) {
			minodd = min(minodd, i);
		}
	}

	vector<vector<int>> G(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	vector<vector<int>> D(n, vector<int>(2, LLONG_MAX));
	D[0][0] = 0;
	queue<array<int, 2>> Q;
	Q.push({0, 0});

	while (Q.size()) {
		auto [u, pu] = Q.front(); Q.pop();

		for (int v : G[u]) if (D[v][pu ^ 1] == LLONG_MAX) {
			D[v][pu ^ 1] = D[u][pu] + 1;
			Q.push({v, pu ^ 1});
		}
	}

	int ps = s & 1;
	vector<int> Res(n);

	for (int u = 0; u < n; u++) {
		Res[u] = (D[u][ps] <= s);
		if (minodd != LLONG_MAX) {
			Res[u] |= (D[u][ps ^ 1] <= s - minodd);
		}
		cout << Res[u];
	}
	cout << endl;

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

