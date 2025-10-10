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

	int n, m, k; cin >> n >> m >> k;
	vector<tuple<int, int, int>> ed(m);

	for (auto& [w, u, v] : ed) {
		cin >> u >> v >> w; u--, v--;
	}
	sort(ed.begin(), ed.end());

	vector<int> vert;
	for (int i = 0; i < min(m, k); i++) {
		auto [w, u, v] = ed[i];
		vert.push_back(u);
		vert.push_back(v);
	}

	sort(vert.begin(), vert.end());
	vert.erase(unique(vert.begin(), vert.end()), vert.end());

	int nn = vert.size();
	vector<vector<ll>> d(nn, vector<ll>(nn, LINF));
	for (int i = 0; i < nn; i++) d[i][i] = 0;

	for (int i = 0; i < min(m, k); i++) {
		auto [w, u, v] = ed[i];

		int x = lower_bound(vert.begin(), vert.end(), u) - vert.begin();
		int y = lower_bound(vert.begin(), vert.end(), v) - vert.begin();
		d[x][y] = d[y][x] = min(d[x][y], (ll)w);
	}

	for (int b = 0; b < nn; b++) {
		for (int a = 0; a < nn; a++) {
			for (int c = 0; c < nn; c++) {
				d[a][c] = min(d[a][c], d[a][b] + d[b][c]);
			}
		}
	}

	vector<ll> res;
	for (int i = 0; i < nn; i++) {
		for (int j = i + 1; j < nn; j++) {
			res.push_back(d[i][j]);
		}
	}
	sort(res.begin(), res.end());
	cout << res[k-1] << endl;
    
    return(0);
}
