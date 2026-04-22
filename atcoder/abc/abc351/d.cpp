#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const vector<array<int, 2>> Dirs = {
	{+1, 0},
	{0, +1},
	{-1, 0},
	{0, -1}
};

int solve() {
	int n, m; cin >> n >> m;

	vector<vector<char>> A(n, vector<char>(m));
	vector<vector<int>> Ruim(n, vector<int>(m)), Vis(n, vector<int>(m)), Foi(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char& c = A[i][j];
			cin >> c;
			if (c == '#') {
				Ruim[i][j] = 1;
				for (auto [di, dj] : Dirs) {
					int i_ = i + di, j_ = j + dj;
					if (i_ < 0 or j_ < 0 or i_ >= n or j_ >= m) continue;
					Ruim[i_][j_] = 1;
				}
			}
		}
	}

	int t = 0, cc = 0, res = 1;
	function<void(int, int)> dfs = [&](int ui, int uj) {
		if (Vis[ui][uj] == t) return;
		Vis[ui][uj] = t;
		cc++;

		if (Ruim[ui][uj]) return;
		Foi[ui][uj] = 1;

		for (auto [di, dj] : Dirs) {
			int vi = ui + di, vj = uj + dj;
			if (vi < 0 or vj < 0 or vi >= n or vj >= m or A[vi][vj] == '#') continue;
			dfs(vi, vj);
		}
	};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) if (A[i][j] == '.' and !Ruim[i][j] and !Foi[i][j]) {
			cc = 0;
			t++;
			dfs(i, j);
			res = max(res, cc);
		}
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
