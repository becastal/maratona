#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

signed solve() {
	int n; cin >> n;

	int ini, inj, outi, outj;
	cin >> ini >> inj >> outi >> outj; ini--, inj--, outi--, outj--;

	vector<string> A(n);
	for (auto& i : A) {
		cin >> i;
	}

	vector<array<int, 2>> cc, movs = {
		{-1, 0},
		{0, -1},
		{1, 0},
		{0, 1}
	};
	vector<vector<int>> vis(n, vector<int>(n));
	function<void(int, int)> dfs = [&](int ui, int uj) {
		vis[ui][uj] = 1;
		cc.push_back({ui, uj});

		for (auto [di, dj] : movs) {
			int vi = ui + di, vj = uj + dj;
			if (vi >= 0 and vi < n and vj >= 0 and vj < n and !vis[vi][vj] and A[vi][vj] == '0') {
				dfs(vi, vj);
			}
		}
	};
	dfs(ini, inj);

	if (vis[outi][outj]) return cout << 0 << endl, 0;

	auto cca = cc;
	cc.clear();
	dfs(outi, outj);
	auto ccb = cc;

	int res = LLONG_MAX;
	for (auto [a, b] : cca) {
		for (auto [c, d] : ccb) {
			res = min(res, (a - c) * (a - c) + (b - d) * (b - d));
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
