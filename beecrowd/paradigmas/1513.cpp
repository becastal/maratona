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

void solve(int n, int m, int k) {
	vector<vector<char>> M(n, vector<char>(m));
	vector<vector<int>> d(k+1, vector<int>(k+1, INF));
	vector<ii> pos;
	ii eu;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> M[i][j];
			if (M[i][j] == 'P') pos.emplace_back(i, j);
			if (M[i][j] == 'C') eu = ii(i, j);
		}
	}
	pos.insert(pos.begin(), eu);
	k++;

	auto valido = [&](int i, int j) {
		return i >= 0 and j >= 0 and i < n and j < m and M[i][j] != '#';
	};

	vector<ii> movs = { {1, -2}, {-1, -2}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {2, 1}, {2, -1} };
	auto bfs = [&](int in) {
		queue<ii> q; q.emplace(pos[in]);
		vector<vector<int>> di(n, vector<int>(m, -1));
		di[pos[in].f][pos[in].s] = 0;

		while (q.size()) {
			ii u = q.front(); q.pop();

			for (auto mov : movs) {
				ii v = {u.f + mov.f, u.s + mov.s};

				if (valido(v.f, v.s) and di[v.f][v.s] == -1) {
					q.emplace(v);	
					di[v.f][v.s] = di[u.f][u.s] + 1;
				}
			}
		}

		for (int i = 0; i < k; i++) {
			d[in][i] = d[i][in] = di[pos[i].f][pos[i].s];
		}
	};

	for (int i = 0; i < k; i++) {
		bfs(i);
	}

	vector<vector<int>> dp((1 << k), vector<int>(k, INF));
	dp[1][0] = 0;

	for (int i = 1; i < (1 << k); i++) {
		for (int u = 0; u < k; u++) {
			if (!(i & (1 << u))) continue;


			for (int v = 0; v < k; v++) {
				if (i & (1 << v)) continue;

				int ni = i | (1 << v);
				dp[ni][v] = min(dp[ni][v], dp[i][u] + d[u][v]);
			}
		}
	}

	int res = INF;
	for (int i = 0; i < k; i++) {
		res = min(res, dp[(1 << k)-1][i] + d[0][i]);
	}
	cout << res << endl;
}

int main()
{
    _;

	int n, m, k; 
	while (cin >> n >> m >> k and n) {
		solve(n, m, k);
	}
    
    return(0);
}
