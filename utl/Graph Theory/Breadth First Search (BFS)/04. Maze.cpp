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

	int n, m, k; cin >> n >> m >> k;
	vector<vector<char>> mp(n, vector<char>(m)), vis(n, vector<char>(m, 0));
	int si = -1, sj = -1, cont = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mp[i][j];
			if (si == -1 and mp[i][j] == '.') { 
				si = i, sj = j;
			}
			cont += mp[i][j] == '.';
		}
	}

	auto valido = [&](int i, int j) {
		return i >= 0 and i < n and j >= 0 and j < m and mp[i][j] == '.';
	};

	vector<pair<int, int>> movs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	auto dfs = [&](int i, int j) {
		int preenche = cont - k - 1;
		stack<pair<int, int>> s;
		s.emplace(i, j);
		vis[i][j] = 1;
		
		while (!s.empty() and preenche) {
			auto [ui, uj] = s.top(); s.pop();

			for (auto mov : movs) {
				if (!preenche) break;
				int vi = ui + mov.f, vj = uj + mov.s;
				if (valido(vi, vj) and !vis[vi][vj] and preenche > 0) {
					preenche--;
					vis[vi][vj] = 1;
					s.emplace(vi, vj);
				}
			}
		}
	};
	dfs(si, sj);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mp[i][j] == '.' and !vis[i][j] and k--) {
				cout << 'X';
			} else {
				cout << mp[i][j];
			}
		}
		cout << endl;
	}
    
    return(0);
}
