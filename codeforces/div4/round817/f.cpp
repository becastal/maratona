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

void solve() {
	int n, m; cin >> n >> m;
	vector<string> v(n);
	vector<vector<int>> vis(n, vector<int>(m, 0));
	for (auto& i : v) cin >> i;

	vector<pair<int, int>> movs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	vector<pair<int, int>> movsd = {{1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
	set<pair<int, int>> s, pos;
	
	function<int(int, int)> valido = [&](int i, int j) {
		return i >= 0 and j >= 0 and i < n and j < m and !vis[i][j] and v[i][j] != '.';
	};

	function<void(int, int)> dfs = [&](int i, int j) {
		vis[i][j] = 1;
		pos.emplace(i, j);

		for (auto mov : movs) {
			if (!valido(i + mov.f, j + mov.s)) continue;

			s.insert(mov);
			dfs(i + mov.f, j + mov.s);
		}
	};

	int ok = 1;
	for (int i = 0; i < n and ok; i++) {
		for (int j = 0; j < m and ok; j++) {
			if (v[i][j] == '.' or vis[i][j]) continue;
			s.clear(), pos.clear();

			dfs(i, j);
			ok &= pos.size() == 3;
			ok &= s.size() == 2;
			for (auto [i, j] : pos) {
				for (auto mov : movsd) {
					int ni = i + mov.f, nj = j + mov.s;
					if (ni >= 0 and nj >= 0 and ni < n and nj < m and !pos.count({ni, nj}) and v[ni][nj] == '*') {
						ok = 0;
					}
				}
			}
		}
	}

	cout << (ok ? "YES" : "NO") << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
