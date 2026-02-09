#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n = 2;

	int res = 0;
	for (int mask = 0; mask < (1 << n * n); mask++) {
		vector<vector<int>> vis(n, vector<int>(n, 0));
		vector<vector<int>> ruim(n, vector<int>(n, 0));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ruim[i][j] = mask & (1 << (n * i + j));
			}
		}

		vector<array<int, 2>> movs = {
			{0, 1},
			{1, 0},
			{0, -1},
			{-1, 0}
		};

		function<int(int, int)> valido = [&](int ui, int uj) {
			return ui >= 0 and uj >= 0 and ui < n and uj < n and !ruim[ui][uj] and !vis[ui][uj];
		};

		function<void(int, int)> dfs = [&](int ui, int uj) {
			vis[ui][uj] = 1;

			for (auto [di, dj] : movs) {
				int vi = ui + di, vj = uj + dj;
				if (!valido(vi, vj)) continue;
				dfs(vi, vj);
			}
		};
		if (valido(1, 0)) dfs(1, 0);

		if (vis[0][1]) res++;
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

