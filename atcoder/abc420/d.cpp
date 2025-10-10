#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;
	vector A(n, vector<char>(m));

	int ini, inj, outi, outj;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
			if (A[i][j] == 'S') {
				ini = i, inj = j;
			}

			if (A[i][j] == 'G') {
				outi = i, outj = j;
			}
		}
	}


	vector<array<int, 2>> movs = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	auto valido = [&](int i, int j) { return i >= 0 and j >= 0 and i < n and j < m and A[i][j] != '#'; };
	auto bfs = [&]() {
		vector D(n, vector(m, vector<int>(2, INT_MAX)));
		D[ini][inj][0] = 0;	

		queue<array<int, 3>> Q; Q.push({ini, inj, 0});

		while (Q.size()) {
			auto [ui, uj, up] = Q.front(); Q.pop();

			for (auto [di, dj] : movs) {
				int vi = ui + di, vj = uj + dj;

				if (!valido(vi, vj)) continue;
				int vp = up ^ (A[vi][vj] == '?');
				if (D[vi][vj][vp] != INT_MAX or (A[vi][vj] == (vp ? 'o' : 'x'))) continue;

				D[vi][vj][vp] = D[ui][uj][up] + 1;
				Q.push({vi, vj, vp});
			}
		}

		return min(D[outi][outj][0], D[outi][outj][1]);
	};

	int res = bfs();

	cout << (res == INT_MAX ? -1 : res) << endl;

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

