#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const vector<array<int, 2>> Dirs = {
	{1, 0},
	{0, 1},
	{-1, 0},
	{0, -1}
};

int solve() {
	int n, m; cin >> n >> m;
	vector<vector<char>> A(n, vector<char>(m));

	int ini = -1, inj = -1;
	int outi = -1, outj = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			auto& c = A[i][j];
			cin >> c;

			if (c == 'S') {
				ini = i, inj = j;
			} else if (c == 'T') {
				outi = i, outj = j;
			}
		}
	}

	int k; cin >> k;
	vector<array<int, 3>> B(k);
	for (auto &[a, b, c] : B) { 
		cin >> a >> b >> c; a--, b--;
	}
	B.push_back({ini, inj, 0});
	B.push_back({outi, outj, 0});

	auto bfs = [&](int si, int sj) {
		vector<vector<int>> D(n, vector<int>(m, LLONG_MAX)); D[si][sj] = 0;
		queue<array<int, 2>> Q; Q.push({si, sj});

		while (Q.size()) {
			auto [ui, uj] = Q.front(); Q.pop();

			for (auto [di, dj] : Dirs) {
				int vi = ui + di, vj = uj + dj;
				if (vi < 0 or vj < 0 or vi >= n or vj >= m or D[vi][vj] != LLONG_MAX or A[vi][vj] == '#') continue;
				D[vi][vj] = D[ui][uj] + 1;
				Q.push({vi, vj});
			}
		}

		return D;
	};

	vector<vector<int>> G(k + 2);
	for (int i = 0; i < k + 2; i++) {
		auto [ui, uj, ut] = B[i];

		auto D = bfs(ui, uj);
		for (int j = 0; j < k + 2; j++) {
			auto [vi, vj, vt] = B[j];
			if (D[vi][vj] <= ut) {
				G[i].push_back(j);
			}
		}
	}

	vector<int> Vis(k + 2);
	function<void(int)> dfs = [&](int u) {
		Vis[u] = 1;

		for (int v : G[u]) if (!Vis[v]) {
			dfs(v);
		}
	};
	dfs(k);

	cout << (Vis[k + 1] ? "Yes" : "No") << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

