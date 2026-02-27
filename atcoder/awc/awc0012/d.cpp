#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m; cin >> n >> m;
	vector<string> A(n);
	for (auto& i : A) {
		cin >> i;
	}

	deque<array<int, 2>> Q; Q.push_front({0, 0});
	vector<vector<int>> D(n, vector<int>(m, LLONG_MAX)); D[0][0] = 0;
	vector<array<int, 2>> movs = {
		{1, 0},
		{0, 1},
		{-1, 0},
		{0, -1},
	};

	while (Q.size()) {
		auto [ui, uj] = Q.front(); Q.pop_front();

		for (auto [di, dj] : movs) {
			int vi = ui + di, vj = uj + dj;
			if (vi < 0 or vj < 0 or vi >= n or vj >= m) continue;

			//printf("(%lld, %lld) -> (%lld, %lld)\n", ui, uj, vi, vj);
			int w = A[vi][vj] == '#';
			if (D[vi][vj] > D[ui][uj] + w) {
				D[vi][vj] = D[ui][uj] + w;
				if (w) {
					Q.push_back({vi, vj});
				} else {
					Q.push_front({vi, vj});
				}
			}
		}
	}
	cout << D[n-1][m-1] << endl;

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

