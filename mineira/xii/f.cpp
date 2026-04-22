#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int mod = 998244353;
const vector<array<int, 2>> Dir = {
	{0, 1},
	{1, 0},
	{-1, 0},
	{0, -1},
};

int exp(int a, int b) {
	if (!b) return 1;
	return (b & 1 ? a : 1) * exp(a * a % mod, b / 2) % mod;
}

int solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<vector<char>> A(n, vector<char>(m));

	int ini = -1, inj = -1;
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) {
			char& c = A[i][j];
			cin >> c;

			if (c == 'R') {
				ini = i, inj = j;	
			}
		}
	}

	vector<vector<int>> D(n, vector<int>(m, -1)); D[ini][inj] = 0;
	queue<array<int, 2>> Q; Q.push({ini, inj});
	vector<int> C(n * m);

	int mn = n * m - 1;
	while (Q.size()) {
		auto [ui, uj] = Q.front(); Q.pop();
		if (A[ui][uj] == 'Q') {
			mn = min(mn, D[ui][uj]);
		}
		if (A[ui][uj] == '.') {
			C[D[ui][uj]]++;
		}

		for (auto [di, dj] : Dir) {
			int vi = ui + di, vj = uj + dj;
			if (vi < 0 or vj < 0 or vi >= n or vj >= m or A[vi][vj] == '#' or D[vi][vj] != -1) continue;
			D[vi][vj] = D[ui][uj] + 1;
			Q.push({vi, vj});
		}
	}

	vector<int> Fat(n * m, 1);
	for (int i = 2; i < n * m; i++) {
		Fat[i] = Fat[i-1] * i % mod;
	}

	vector<int> Invfat(n * m, 1);
	Invfat.back() = exp(Fat.back(), mod - 2);
	for (int i = n * m - 2; i >= 1; i--) {
		Invfat[i] = Invfat[i + 1] * (i + 1) % mod;
	}

	auto choose = [&](int a, int b) -> int {
		if (b < 0 or b > a) return 0;
		return Fat[a] * Invfat[b] % mod * Invfat[a - b] % mod;
	};

	int res = 0, livres = 0;
	for (int d = n * m - 1; d >= 1; d--) {
		livres += C[d];
		if (d <= mn) {
			res = (res + choose(livres, k)) % mod;
		}
	}
	res = (res * exp(choose(livres, k), mod - 2)) % mod;
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

