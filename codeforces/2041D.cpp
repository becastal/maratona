#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m, s, t; cin >> n >> m;

	vector<char> A(n * m);
	for (int i = 0; i < n * m; i++) {
		cin >> A[i];
		if (A[i] == 'S') {
			s = i;
		} else if (A[i] == 'T') {
			t = i;	
		}
	}

	vector<vector<vector<int>>> D(n * m, vector<vector<int>>(5, vector<int>(4, LLONG_MAX))); D[s][4][0] = 0;
	queue<array<int, 3>> Q; Q.push({s, 4, 0});
	const vector<array<int, 2>> mov = {
		{-1, 0},
		{0, -1},
		{1, 0},
		{0, 1}
	};

	while (Q.size()) {
		auto [u, dir, cont] = Q.front(); Q.pop();
		int ui = u / m, uj = u % m;

		//cout << "(" << ui << ", " << uj << ")\n";
		for (int dir_ = 0; dir_ < 4; dir_++) {
			int cont_ = (dir == dir_) ? cont + 1 : 1;
			if (cont_ > 3) continue;

			auto [di, dj] = mov[dir_];
			int vi = ui + di, vj = uj + dj, v = vi * m + vj;
			if (vi < 0 or vj < 0 or vi >= n or vj >= m or A[v] == '#' or D[v][dir_][cont_] != LLONG_MAX) continue;
			D[v][dir_][cont_] = D[u][dir][cont] + 1;
			Q.push({v, dir_, cont_});
		}
	}
	
	int res = LLONG_MAX;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			res = min(res, D[t][i][j]);
		}
	}

	if (res == LLONG_MAX) res = -1;
	cout << res << endl;

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

