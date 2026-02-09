#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
	definitivamente caminho hamiltoniano.
*/

const vector<array<int, 2>> movs = {
	{0, 1},
	{-1, 0},
	{1, 0},
	{0, -1}
};

int solve() {
	int n, m, t; cin >> n >> m >> t;
	
	array<int, 2> I, F;
	vector<array<int, 2>> C;

	vector A(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			A[i][j] = c;
			if (c == 'S') I = {i, j};
			else if (c == 'G') F = {i, j};
			else if (c == 'o') {
				C.push_back({i, j});
			}
		}
	}
	C.insert(C.begin(), I);
	C.insert(C.end(), F);

	auto valido = [&](int i, int j) {
		return i >= 0 and i < n and j >= 0 and j < m and A[i][j] != '#';
	};
	auto bfs = [&](array<int, 2> in) {
		vector D(n, vector<int>(m, -1)); D[in[0]][in[1]] = 0;
		queue<array<int, 2>> Q; Q.push(in);
		
		while (Q.size()) {
			auto [ui, uj] = Q.front(); Q.pop();

			for (auto [di, dj] : movs) {
				int vi = ui + di, vj = uj + dj;
				if (!valido(vi, vj) or D[vi][vj] != -1) continue;
				D[vi][vj] = D[ui][uj] + 1;
				Q.push({vi, vj});
			}
		}

		return D;
	};

	int nn = (int)C.size();
	vector D(nn, vector<int>(nn));

	for (int u = 0; u < nn; u++) {
		auto Du = bfs(C[u]);

		for (int v = 0; v < nn; v++) {
			D[u][v] = Du[C[v][0]][C[v][1]];
		}
	}
	if (D[0][nn-1] > t or D[0][nn-1] == -1) return cout << -1 << endl, 0;

	vector dp((1 << nn), vector<ll>(nn, INT_MAX));
	dp[1][0] = 0;

	for (int mask = 1; mask < (1 << nn); mask++) {
		for (int u = 0; u < nn; u++) if ((mask >> u & 1) and dp[mask][u] != INT_MAX) {
			for (int v = 0; v < nn; v++) if ((mask >> v & 1 ^ 1) and D[u][v] != -1) {
				int mask_ = mask | (1 << v);
				dp[mask_][v] = min(dp[mask_][v], dp[mask][u] + D[u][v]);
			}
		}
	}

	int res = 0;
	for (int mask = 0; mask < (1 << nn); mask++) if ((mask >> 0 & 1) and (mask >> nn-1 & 1)) {
		if (dp[mask][nn-1] <= t) {
			res = max(res, __builtin_popcount(mask) - 2);
		}
	}
	cout << res << endl;

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

