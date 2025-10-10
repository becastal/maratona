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
	int x, y; cin >> x >> y; x--, y--;

	vector<pair<int, int>> movs = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
	auto valido = [&](int i, int j) { return i >= 0 and i < n and j >= 0 and j < m; };

	vector<vector<int>> A(n, vector<int>(m));
	for (auto& i : A) for (auto& j : i) cin >> j;

	auto sol = [&](int ini, int inj) {

		int res = INT_MAX, agr = 0;
		for (int i = 30; i >= 0; i--) {
			vector<vector<int>> vis(n, vector<int>(m, 0));

			function<void(int, int)> dfs = [&](int ui, int uj) {
				vis[ui][uj] = 1;

				for (auto [di, dj] : movs) {
					int vi = ui + di, vj = uj + dj;
					if (!valido(vi, vj) or vis[vi][vj]) continue;
					if ((A[vi][vj] & agr) or (A[vi][vj] & (1 << i))) continue;
					dfs(vi, vj);
				}
			};
			dfs(ini, inj);

			if (vis[n-1][m-1]) {
				res ^= (1 << i);	
				agr |= (1 << i);
			}
		}

		return res;
	};

	cout << sol(0, 0) << ' ' << sol(x, y) << endl;

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
