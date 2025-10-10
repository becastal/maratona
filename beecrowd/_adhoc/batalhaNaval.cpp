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

int main()
{
    _;

	int n, m; cin >> n >> m;
	vector<vector<char>> mp(n, vector<char> (m));	
	vector<vector<int>> acertado(n, vector<int> (m, 0)), vis(n, vector<int> (m, 0));	

	for (auto& l : mp) for (auto& c : l) cin >> c;

	int k; cin >> k;
	for (int i = 0, r, c; i < k; i++) {
		cin >> r >> c; r--, c--;
		acertado[r][c] = 1;
	}

	auto valido = [&] (int i, int j) {
		return i >= 0 and j >= 0 and i < n and j < m and mp[i][j] == '#' and !vis[i][j];
	};

	vector<ii> movs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	auto dfs = [&] (int i, int j) {
		stack<ii> s; s.push(ii(i, j));
		vis[i][j] = 1;
		
		int res = 1;
		while (!s.empty()) {
			ii u = s.top();	s.pop();
			res &= acertado[u.f][u.s];

			for (ii mov : movs) {
				ii v; v.f = u.f + mov.f, v.s = u.s + mov.s;
				if (!valido(v.f, v.s)) continue;
				s.push(v);
				vis[v.f][v.s] = 1;
			}
		}

		return res;
	};

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (valido(i, j)) {
				res += dfs(i, j);
			}
		}
	}
	cout << res << endl;
    
    return(0);
}
