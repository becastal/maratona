#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const vector<array<int, 2>> Dir = {
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0},
};

int solve() {
	int n, d; cin >> n >> d;

	vector<vector<char>> A(n, vector<char>(n));

	vector<vector<int>> Dparede(n, vector<int>(n, LLONG_MAX)), Ds(Dparede);
	queue<array<int, 2>> Qparede, Qs;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char& c = A[i][j]; cin >> c;
			if (c == 'S') {
				Qs.push({i, j});
				Ds[i][j] = 0;
			} else if (c == '#') {
				Qparede.push({i, j});
				Dparede[i][j] = 0;
			}
		}
	}

	auto valido = [&](int i, int j) {
		if (i < 0 or j < 0 or i >= n or j >= n) return 0;
		return 1;
	};

	while (Qparede.size()) {
		auto [ui, uj] = Qparede.front(); Qparede.pop();

		for (auto [di, dj] : Dir) {
			int vi = ui + di, vj = uj + dj;
			if (!valido(vi, vj) or A[vi][vj] == '#' or Dparede[vi][vj] != LLONG_MAX) continue;
			Dparede[vi][vj] = Dparede[ui][uj] + 1;
			Qparede.push({vi, vj});
		}
	}

	vector<vector<int>> Db(n, vector<int>(n, -1));
	priority_queue<array<int, 3>> Qb;

	while (Qs.size()) {
		auto [ui, uj] = Qs.front(); Qs.pop();
		int tam = Ds[ui][uj] / d;

		Db[ui][uj] = max(Db[ui][uj], tam);

		for (auto [di, dj] : Dir) {
			int vi = ui + di, vj = uj + dj;
			if (!valido(vi, vj) or A[vi][vj] == '#' or Ds[vi][vj] != LLONG_MAX) continue;
			if (Dparede[vi][vj] < tam + 1) continue;

			Db[vi][vj] = max(Db[vi][vj], tam);

			if ((Ds[ui][uj] + 1) % d != 0 or Dparede[vi][vj] >= tam + 2) {
				Ds[vi][vj] = Ds[ui][uj] + 1;
				Qs.push({vi, vj});
				Db[vi][vj] = max(Db[vi][vj], (Ds[ui][uj] + 1) / d);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (Db[i][j] != -1) {
				Qb.push({Db[i][j], i, j});
			}
		}
	}

	while (Qb.size()) {
		auto [ut, ui, uj] = Qb.top(); Qb.pop();
		if (ut != Db[ui][uj] or !ut) continue;

		for (auto [di, dj] : Dir) {
			int vi = ui + di, vj = uj + dj;
			if (!valido(vi, vj) or A[vi][vj] == '#') continue;

			if (Db[vi][vj] < ut - 1) {
				Db[vi][vj] = ut - 1;
				Qb.push({ut - 1, vi, vj});
			}
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (A[i][j] != '#' and Db[i][j] != -1) {
				res++;
			}
			//if (A[i][j] != '#' and Db[i][j] != -1) A[i][j] = 'x';
		}
	}

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << A[i][j];
	//	}
	//	cout << endl;
	//}
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

