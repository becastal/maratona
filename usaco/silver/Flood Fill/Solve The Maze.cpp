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

int solve() {
	int n, m; cin >> n >> m;
	vector<string> a(n);
	for (auto& i : a) cin >> i;

	vector<vector<int>> vis(n, vector<int>(m, 0));
	auto valido = [&](int i, int j) {
		return i >= 0 and i < n and j >= 0 and j < m;
	};
	vector<pair<int, int>> movs = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

	function<void(int, int)> dfs = [&](int ui, int uj) {
		vis[ui][uj] = 1;

		for (auto [di, dj] : movs) {
			int vi = ui + di, vj = uj + dj;
			if (valido(vi, vj) and a[vi][vj] != '#' and !vis[vi][vj]) dfs(vi, vj);
		}
	};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'B') {
				for (auto [di, dj] : movs) {
					int vi = i + di, vj = j + dj;
					if (!valido(vi, vj)) continue;
					if (a[vi][vj] != '.' and a[vi][vj] != '#') continue;
					a[vi][vj] = '#';
				}
			}
		}
	}

	if (a[n-1][m-1] != '#') dfs(n-1, m-1);
	int ok = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'G') ok &= vis[i][j];
			if (a[i][j] == 'B') ok &= !vis[i][j];
		}
	}

	cout << (ok ? "YES" : "NO") << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
