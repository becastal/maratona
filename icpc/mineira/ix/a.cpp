#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m, t, ini, inj;
	cin >> n >> m >> t >> ini >> inj; ini--, inj--;

	vector<string> A(n);
	for (auto& i : A) cin >> i;
	vector D(n, vector<int>(m, INT_MAX));
	D[ini][inj] = 0;

	vector<array<int, 2>> movs = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}, };
	auto valido = [&](int i, int j) { return i >= 0 and i < n and j >= 0 and j < m and A[i][j] != '#'; };
	auto bfs = [&]() {
		queue<array<int, 2>> Q; Q.push({ini, inj});

		while (Q.size()) {
			auto [ui, uj] = Q.front(); Q.pop();

			for (auto [di, dj] : movs) {
				int vi = di + ui, vj = dj + uj;
				if (valido(vi, vj) and D[vi][vj] == INT_MAX) {
					Q.push({vi, vj});
					D[vi][vj] = D[ui][uj] + 1;
				}
			}
		}
	};
	bfs();

	int num = 0, den = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			num += D[i][j] <= t;
			den += A[i][j] == '.';
		}
	}

	int g = gcd(num, den);
	cout << num / g << ' '  << den / g << endl;

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

