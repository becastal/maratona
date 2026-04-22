#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const vector<array<int, 2>> Dirs = {
	{0, 1},
	{1, 0},
	{-1, 0},
	{0, -1}
};

int solve() {
	int n, t; cin >> n >> t;

	vector<vector<int>> A(n, vector<int>(n)), D(n, vector<int>(n, LLONG_MAX));
	vector<vector<vector<array<int, 3>>>> G(n, vector<vector<array<int, 3>>>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}
	
	auto Viz = [&](int i, int j) -> vector<array<int, 2>> {
		vector<array<int, 2>> Ret;
		for (auto [di, dj] : Dirs) {
			int i_ = i + di, j_ = j + dj;
			if (i_ < 0 or j_ < 0 or i_ >= n or j_ >= n) continue;
			Ret.push_back({i_, j_});
		}
		return Ret;
	};

	for (int ai = 0; ai < n; ai++) {
		for (int aj = 0; aj < n; aj++) {
			for (auto [bi, bj] : Viz(ai, aj)) {
				for (auto [ci, cj] : Viz(bi, bj)) {
					for (auto [di, dj] : Viz(ci, cj)) {
						G[ai][aj].push_back({di, dj, 3 * t + A[di][dj]});
					}
				}
			}
		}
	}

	priority_queue<array<int, 3>> Pq; Pq.push({0, 0, 0});
	D[0][0] = 0;

	while (Pq.size()) {
		auto [du, ui, uj] = Pq.top(); Pq.pop();
		if (-du != D[ui][uj]) continue;

		for (auto [vi, vj, w] : G[ui][uj]) if (D[vi][vj] > D[ui][uj] + w) {
			D[vi][vj] = D[ui][uj] + w;
			Pq.push({-D[vi][vj], vi, vj});
		}
	}

	int res = LLONG_MAX;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int d = abs(i - (n-1)) + abs(j - (n-1));
			if (d <= 2) {
				res = min(res, d * t + D[i][j]);
			}
		}
	}
	cout << res << endl;

	return(0);
}
void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

signed main()
{
    _;
	setIO("visitfj");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
