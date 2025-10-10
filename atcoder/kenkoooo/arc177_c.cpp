#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<vector<int>> A(n, vector<int>(n)), B(A);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c; cin >> c;
			A[i][j] = (c == 'R');
			B[i][j] = !(c == 'R');
		}
	}

	vector<pair<int, int>> movs = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
	auto valido = [&](int i, int j) { return i >= 0 and j >= 0 and i < n and j < n; };
	auto bfs = [&](vector<vector<int>>& C, int ini, int inj, int outi, int outj) {
		vector<vector<int>> D(n, vector<int>(n, INF));
		D[ini][inj] = 0;

		deque<pair<int, int>> Q;
		Q.emplace_front(ini, inj);

		while (Q.size()) {
			auto [ui, uj] = Q.front(); Q.pop_front();

			for (auto [di, dj] : movs) {
				int vi = ui + di, vj = uj + dj;
				if (!valido(vi, vj)) continue;

				int w = !C[vi][vj];
				if (D[vi][vj] <= D[ui][uj] + w) continue;
				D[vi][vj] = D[ui][uj] + w;
				if (w) Q.emplace_back(vi, vj);
				else Q.emplace_front(vi, vj);
			}
		}

		return D[outi][outj];
	};

	cout << bfs(A, 0, 0, n-1, n-1) + bfs(B, 0, n-1, n-1, 0) << endl;

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
