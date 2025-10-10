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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("lightson");
	int n, m; cin >> n >> m;
	vector<vector<int>> vis(n, vector<int>(n, 0)), lig(n, vector<int>(n, 0));
	vector<vector<vector<pair<int, int>>>> a(n, vector<vector<pair<int, int>>>(n));

	for (int i = 0, x, y, xx, yy; i < m; i++) {
		cin >> x >> y >> xx >> yy; x--, y--, xx--, yy--;
		a[x][y].emplace_back(xx, yy);
	}

	auto valido = [&](int i, int j) {
		return i >= 0 and i < n and j >= 0 and j < n;
	};
	vector<pair<int, int>> movs = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

	function<void(int, int)> dfs = [&](int ui, int uj) {
		vis[ui][uj] = lig[ui][uj] = 1;

		for (auto [x, y] : a[ui][uj]) {
			lig[x][y] = 1;
			for (auto [di, dj] : movs) {
				int vi = x + di, vj = y + dj;	
				if (!valido(vi, vj)) continue;
				if (vis[vi][vj] and !vis[x][y]) dfs(x, y);
			}
		}

		for (auto [di, dj] : movs) {
			int vi = ui + di, vj = uj + dj;	
			if (!valido(vi, vj) or !lig[vi][vj]) continue;
			else if (!vis[vi][vj]) dfs(vi, vj);
		}
	};
	dfs(0, 0);

	int res = 0;
	for (auto& i : lig) res += accumulate(i.begin(), i.end(), 0);
	cout << res << endl;
	
    return(0);
}
