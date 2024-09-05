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

	int n, m, k; cin >> n >> m >> k;

	ii x;
	vector<vector<char>> mp(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 'X') x = ii(i, j);
		}
	}

	vector<vector<int>> d(n, vector<int>(m, -1)), cam(n, vector<int>(m, -1));
	vector<vector<ii>> pai(n, vector<ii>(m, ii(-1, -1)));
	vector<ii> movs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

	auto valido = [&](int i, int j) {
		return i >= 0 and j >= 0 and i < n and j < m and mp[i][j] != '*';
	};

	auto bfs = [&]() {
		queue<ii> q; q.emplace(x.f, x.s);
		d[x.f][x.s] = 0;

		while (!q.empty()) {
			auto [ui, uj] = q.front(); q.pop();

			for (int i = 0; i < 4; i++) {
				ii mov = movs[i];
				int vi = ui + mov.f, vj = uj + mov.s;
				if (!valido(vi, vj) or d[vi][vj] != -1) continue;
				
				q.emplace(vi, vj);
				d[vi][vj] = d[ui][uj] + 1;
				pai[vi][vj] = ii(ui, uj);
				cam[vi][vj] = i;
			}
		}
	};
	bfs();

	ii a, b;
	a = b = ii(-1, -1);
	for (int i = 0; i < n and a.f == -1; i++) {
		for (int j = 0; j < m and a.f == -1; j++) {
			if (d[i][j] == -1) continue;

			if (2*d[i][j] == k) {
				a = b = ii(i, j);
			}

			for (auto mov : movs) {
				int ni = i + mov.f, nj = j + mov.s;

				if (valido(ni, nj) and d[ni][nj] != -1) {
					if (d[i][j] + d[ni][nj] + 1 == k) {
						a = ii(i, j);
						b = ii(ni, nj);
						break;
					}
				}
			}
		}
	}

	if (a.f == -1) return cout << "IMPOSSIBLE" << endl, 0;
	
	// agora so retornar x -> a -> b -> x;

    return(0);
}

