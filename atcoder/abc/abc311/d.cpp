#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;

	vector<vector<int>> vis(n, vector<int>(m));
	vector<string> A(n);
	for (auto& i : A) cin >> i;

	const vector<array<int, 2>> movs = {
		{-1, 0},
		{0, -1},
		{1, 0},
		{0, 1}
	};
	function<int(int, int)> valido = [&](int i, int j) {
		return i >= 0 and j >= 0 and i < n and j < m and A[i][j] != '#';
	};
	function<void(int, int)> dfs = [&](int ui, int uj) {
		vis[ui][uj] = 2;

		for (auto [di, dj] : movs) {
			int vi = ui, vj = uj;
			while (1) {
				int vi_ = vi + di, vj_ = vj + dj;
				if (valido(vi_, vj_)) {
					vis[vi][vj] = max(vis[vi][vj], 1);
					vi = vi_, vj = vj_;
				}
				else break;
			}
			if (vis[vi][vj] != 2) dfs(vi, vj);
		}
	};
	dfs(1, 1);

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			res += !!vis[i][j];
		}
	}
	cout << res << endl;

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

