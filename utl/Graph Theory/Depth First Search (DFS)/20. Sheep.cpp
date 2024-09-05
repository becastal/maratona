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
	vector<vector<char>> mp(n, vector<char>(m));

	for (auto& l : mp) {
		for (auto& c : l) {
			cin >> c;
		}
	}

	vector<vector<bool>> vis(n, vector<bool>(m, 0));
	vector<ii> movs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

	auto saiu = [&] (int i, int j) {
		return i < 0 or j < 0 or i >= n or j >= m;
	};

	auto valido = [&] (int i, int j) {
		return i >= 0 and j >= 0 and i < n and j < m and !vis[i][j] and mp[i][j] != '#';
	};

	auto dfs = [&] (int i, int j) {
		vis[i][j] = 1;
		stack<ii> s; s.emplace(i, j);

		int K = 0, V = 0, esc = 0;
		while (!s.empty()) {
			auto [ui, uj] = s.top(); s.pop();
			if (mp[ui][uj] == 'k') K++;
			else if (mp[ui][uj] == 'v') V++;

			for (auto mov : movs) {
				int vi = ui + mov.f, vj = uj + mov.s;
				esc |= saiu(vi, vj);
				if (valido(vi, vj)) {
					s.emplace(vi, vj);
					vis[vi][vj] = 1;
				}
			}
		}

		if (esc) return make_pair(K, V);
		if (K > V) return make_pair(K, 0);	
		return make_pair(0, V);
	};

	ii res = {0, 0};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j] and mp[i][j] != '#') {
				auto add = dfs(i, j);
				res.f += add.f, res.s += add.s;
			}
		}
	}

	cout << res.f << ' ' << res.s << endl;
    
    return(0);
}
