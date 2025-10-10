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

int main()
{
    _;

	int n, m, q; cin >> n >> m >> q;
	vector<vector<ll>> d(n, vector<ll>(n, LINF));

	for (int i = 0; i < n; i++) {
		d[i][i] = 0;
	}
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		d[u][v] = min(d[u][v], (ll)w);
		d[v][u] = min(d[v][u], (ll)w);
	}

	for (int b = 0; b < n; b++) {
		for (int a = 0; a < n; a++) {
			for (int c = 0; c < n; c++) {
				d[a][c] = min(d[a][c], d[a][b] + d[b][c]);
			}
		}
	}

	while (q--) {
		int u, v; cin >> u >> v; u--, v--;
		cout << (d[u][v] == LINF ? -1 : d[u][v]) << endl;
	}
    
    return(0);
}
