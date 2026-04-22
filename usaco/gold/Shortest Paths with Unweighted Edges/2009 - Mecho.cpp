#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const vector<array<int, 2>> Dir = {
	{0, -1},
	{0, +1},
	{-1, 0},
	{+1, 0}
};

int solve() {
	int n, s; cin >> n >> s;

	array<int, 2> in, out;
	queue<array<int, 2>> Abelhas;
	vector<vector<int>> D(n, vector<int>(n, LLONG_MAX));

	vector<vector<char>> A(n, vector<char>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char& c = A[i][j];
			cin >> c;

			if (c == 'M') {
				in = {i, j};
				A[i][j] = 'G';
			} else if (c == 'D') {
				out = {i, j};
			} else if (c == 'H') {
				Abelhas.push({i, j});
				D[i][j] = 0;
			}
		}
	}

	auto valido = [&](int i, int j) {
		if (i < 0 or j < 0 or i >= n or j >= n) return 0;
		return 1;
	};

	while (Abelhas.size()) {
		auto [ui, uj] = Abelhas.front(); Abelhas.pop();

		for (auto [di, dj] : Dir) {
			int vi = ui + di, vj = uj + dj;
			if (!valido(vi, vj) or A[vi][vj] != 'G' or D[vi][vj] != LLONG_MAX) continue;
			D[vi][vj] = D[ui][uj] + 1;
			Abelhas.push({vi, vj});
		}
	}

	auto da = [&](int x) {
		auto [ini, inj] = in;
		auto [outi, outj] = out;

		if (D[ini][inj] <= x) return false;
		queue<array<int, 2>> Q;
		vector<vector<array<int, 2>>> Durso(n, vector<array<int, 2>>(n, {LLONG_MAX, LLONG_MAX}));
		Q.push(in);
		Durso[ini][inj] = {x, 0};

		while (Q.size()) {
			auto [ui, uj] = Q.front(); Q.pop();
			array<int, 2> d_ = Durso[ui][uj];
			if (++d_[1] == s) {
				d_[0]++;
				d_[1] = 0;
			}

			for (auto [di, dj] : Dir) {
				int vi = ui + di, vj = uj + dj;

				if (!valido(vi, vj)) continue;
				if (A[vi][vj] != 'G' and A[vi][vj] != 'D') continue;
				if (A[vi][vj] != 'D' and D[vi][vj] <= d_[0]) continue;
				if (Durso[vi][vj] <= d_) continue;

				Durso[vi][vj] = d_;
				Q.push({vi, vj});
			}
		}

		return Durso[outi][outj] != array<int, 2>{LLONG_MAX, LLONG_MAX};
	};

	int l = 0, r = n * n, res = -1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		
		if (da(mid)) {
			l = mid + 1;
			res = mid;
		} else {
			r = mid - 1;	
		}
	}
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

