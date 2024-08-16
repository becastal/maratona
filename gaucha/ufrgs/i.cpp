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

int main()
{
    _;

	int n, m; cin >> n >> m;
	vector<string> mp(n);
	for (auto& l : mp) {
		cin >> l;
	}

	vector<vector<bool>> vis(n, vector<bool>(m, 0));
	vector<pair<int, int>> movs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	function<bool(int, int)> valido = [&](int i, int j) {
		return i >= 0 and j >= 0 and i < n and j < m and mp[i][j] == '.' and !vis[i][j];
	};
	
	function<void(int, int)> dfs = [&](int i, int j) {
		vis[i][j] = 1;
		for (auto mov : movs) {
			auto ii = i + mov.f, jj = j + mov.s;
			if (valido(ii, jj)) {
				dfs(ii, jj);
			}
		}
	};

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j] and mp[i][j] == '.') {
				res++;
				dfs(i, j);
			}
		}
	}

	cout << res << endl;
    
    return(0);
}
