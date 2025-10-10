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
typedef pair<int, int> ii;

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> M(n, vector<int>(m)), vis(n, vector<int>(m, 0));
	vector<ii> movs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

	for (auto& l : M) for (auto& c : l) cin >> c;
	
	auto valido = [&](ii v) {
		return v.f >= 0 and v.f < n and v.s >= 0 and v.s < m and M[v.f][v.s] and !vis[v.f][v.s];
	};

	function<int(ii)> dfs = [&](ii u) {
		vis[u.f][u.s] = 1;
		int agr = M[u.f][u.s];

		for (ii mov : movs) {
			ii v = {u.f + mov.f, u.s + mov.s};
			if (valido(v)) {
				agr += dfs(v);
			}
		}
		return agr;
	};

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j] and M[i][j]) {
				res = max(res, dfs({i, j}));
			}
		}
	}
	cout << res << endl;
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
