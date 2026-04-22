#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const vector<array<int, 2>> Dir = {
	{1, 0},
	{0, 1},
	{-1, 0},
	{0, -1}
};
int solve() {
	int n, m; cin >> n >> m;
	vector<string> A(n);

	for (auto& i : A) {
		cin >> i;
	}
	vector<vector<int>> Vis(n, vector<int>(m));

	int bom = 0;
	function<void(int, int)> dfs = [&](int ui, int uj) {
		Vis[ui][uj] = 1;

		for (auto [di, dj] : Dir) {
			int vi = ui + di, vj = uj + dj;

			if (vi < 0 or vj < 0 or vi >= n or vj >= m) {
				bom = 0;
				continue;
			}
			if (A[vi][vj] == '#' or Vis[vi][vj]) continue;
			dfs(vi, vj);
		}
	};

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) if (!Vis[i][j] and A[i][j] == '.') {
			bom = 1;
			dfs(i, j);	
			res += bom;
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

