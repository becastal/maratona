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
	int n, m; cin >> n >> m;
	vector<string> A(n), B(n);

	for (auto& i : A) cin >> i;
	for (auto& i : B) cin >> i;

	vector<string> C(n, string(m, '?'));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			C[i][j] = (A[i][j] == '#' or B[i][j] == '#' ? '#' : '.');
		}
	}

	vector<array<int, 2>> movs = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
	auto valido = [&](int i, int j) { return i >= 0 and j >= 0 and i < n and j < m; };
	auto bfs = [n, m, &movs, &valido](vector<string>& A) {
		vector D(n, vector<int>(m, INF)); D[0][0] = 0;
		queue<array<int, 2>> Q; Q.push({0, 0});

		while (Q.size()) {
			auto [ui, uj] = Q.front(); Q.pop();

			for (auto [di, dj] : movs) {
				int vi = ui + di, vj = uj + dj;
				if (!valido(vi, vj) or A[vi][vj] == '#' or D[vi][vj] != INF) continue;
				D[vi][vj] = D[ui][uj] + 1;
				Q.push({vi, vj});
			}
		}
		return D;
	};

	auto Da = bfs(A);
	auto Db = bfs(B);
	auto Dc = bfs(C);

	if (Dc[n-1][m-1] == INF) return cout << "NO" << endl, 0;
	cout << (Da[n-1][m-1] == Db[n-1][m-1] and Da[n-1][m-1] == Dc[n-1][m-1] ? "YES" : "NO") << endl;

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
