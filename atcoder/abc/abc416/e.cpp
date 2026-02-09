#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	// talvez so floyd e um jeito esperto de atualizar.
	int n, m; cin >> n >> m;
	vector<vector<ll>> D(n+1, vector<ll>(n+1, LINF));
	for (int i = 0; i <= n; i++) D[i][i] = 0;

	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		D[u][v] = min(D[u][v], ll(w));
		D[v][u] = min(D[v][u], ll(w));
	}

	int k, t; cin >> k >> t;
	vector<int> Ar(k);
	for (int& i : Ar) {
		cin >> i, i--;
		D[i][n] = 0;
		D[n][i] = t;
	}

	for (int b = 0; b <= n; b++) {
		for (int a = 0; a <= n; a++) {
			for (int c = 0; c <= n; c++) {
				D[a][c] = min(D[a][c], D[a][b] + D[b][c]);
			}
		}
	}

//	// se o(n^3 + qn^2) passar
//	// query 1 em n^2: so os dois lacos internos do floyd.
	int q; cin >> q;
	while (q--) {
		int tp; cin >> tp;

		if (tp == 3) {
			ll res = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					res += (D[i][j] == LINF ? 0 : D[i][j]);
				}
			}
			cout << res << endl;
		} else if (tp == 1) {
			int u, v, w; cin >> u >> v >> w; u--, v--;

			//auto D_ = D;
			for (int a = 0; a <= n; a++) {
				for (int c = 0; c <= n; c++) {
					D[a][c] = min(D[a][c], D[a][u] + w + D[v][c]);
					D[a][c] = min(D[a][c], D[a][v] + w + D[u][c]);
				}
			}
		} else if (tp == 2) {
			int u; cin >> u; u--;

			//auto D_ = D;
			for (int a = 0; a <= n; a++) {
				for (int c = 0; c <= n; c++) {
					D[a][c] = min(D[a][c], D[a][u] + 0 + D[n][c]);
					D[a][c] = min(D[a][c], D[a][n] + t + D[u][c]);
				}
			}
		}
	}

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
