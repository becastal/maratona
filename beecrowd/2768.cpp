#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
const ll LINF = 1e18+10;

int solve(int n, int m) {
	vector<vector<array<int, 2>>> G(n);

	vector D(n, vector<ll>(n, LLONG_MAX));
	for (int i = 0; i < n; i++) D[i][i] = 0;

	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
		D[u][v] = D[v][u] = min(D[u][v], ll(w));
	}


	int q; cin >> q;
	vector<ll> res(q);
	vector<array<int, 4>> Q;
	for (int i = 0, u, v, k; i < q; i++) {
		cin >> u >> v >> k; u--, v--, k--;
		Q.push_back({k, u, v, i});
	}


	sort(all(Q));
	for (int i = 0, b = 0; i < q; i++) {
		auto [k, u, v, id] = Q[i];

		while (b <= k) {
			for (int a = 0; a < n; a++) {
				for (int c = 0; c < n; c++) if (D[a][b] != LLONG_MAX and D[b][c] != LLONG_MAX) {
					D[a][c] = min(D[a][c], D[a][b] + D[b][c]);
				}
			}

			b++;
		}

		res[id] = (D[u][v] != LLONG_MAX ? D[u][v] : -1);
	}

	for (ll i : res) cout << i << endl;

	return(0);
}

int main()
{
    _;

	int n, m;
	while (cin >> n >> m) {
		solve(n, m);
	}
    
    return(0);
}

