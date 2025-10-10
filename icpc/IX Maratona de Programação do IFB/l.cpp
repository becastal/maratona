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

	vector<vector<int>> vis(n, vector<int>(m, 0));
	vector<string> M(n);

	for (auto& i : M) cin >> i;

	auto valido = [&](int i, int j) {
		return i >= 0 and j >= 0 and i < n and j < m and !vis[i][j] and M[i][j] == 'F';
	};

	vector<pair<int, int>> movs = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

	function<void(int, int)> dfs = [&](int ui, int uj) {
		vis[ui][uj] = 1;

		for (auto [di, dj] : movs) {
			if (!valido(ui + di, uj + dj)) continue;
			dfs(ui + di, uj + dj);
		}
	};

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!valido(i, j)) continue;
			dfs(i, j);
			res++;
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
