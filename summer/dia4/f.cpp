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

	int n, m; cin >> n >> m;
	vector<vector<vector<ll>>> d(3, vector<vector<ll>>(n, vector<ll>(n, LINF)));

	for (int i = 0, u, v, w, tp; i < m; i++) {
		cin >> u >> v >> w >> tp;
		u--, v--;

		for (int j = 0; j <= tp; j++) {
			d[j][u][v] = min(d[j][u][v], (ll)w);
		}
	}

	for (int tp = 0; tp <= 2; tp++) {
		for (int i = 0; i < n; i++) {
			d[tp][i][i] = 0;		
		}
	}

	for (int tp = 0; tp <= 2; tp++) {
		for (int b = 0; b < n; b++) {
			for (int a = 0; a < n; a++) {
				for (int c = 0; c < n; c++) {
					d[tp][a][c] = min(d[tp][a][c], d[tp][a][b] + d[tp][b][c]);
					//if (tp == 2) d[2][a][c] = min(d[2][a][c], 2LL*(d[1][a][b] + d[1][b][c]) + (d[0][c][b] + d[0][b][a]));
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << (d[2][i][j] == LINF ? -1 : d[2][i][j]) << ' ';
		}
		cout << endl;
	}
    
    return(0);
}
