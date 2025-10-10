#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int vis[300][300];
void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("multimoo");

	int n; cin >> n;
	vector<vector<int>> A(n, vector<int>(n));
	for (auto& i : A) for (auto& j : i) cin >> j;

	vector<pair<int, int>> movs = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
	auto valido = [&](int i, int j) { return i >= 0 and i < n and j >= 0 and j < n; };
	function<void(int, int, int, int, int&)> dfs = [&](int ui, int uj, int c1, int c2, int& tam) {
		vis[ui][uj] = 1;	
		tam++;

		for (auto [di, dj] : movs) {
			int vi = di + ui, vj = dj + uj;
			if (!valido(vi, vj) or vis[vi][vj] or (A[vi][vj] != c1 and A[vi][vj] != c2)) continue;
			dfs(vi, vj, c1, c2, tam);
		}
	};

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tam = 0;
			if (!vis[i][j]) dfs(i, j, A[i][j], A[i][j], tam);
			res = max(res, tam);
		}
	}
	cout << res << endl;

	res = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (res >= n * n / 2) return cout << res << endl, 0;	

			if (A[i][j] != A[i][j-1]) {
				int tam = 0;	
				memset(vis, 0, sizeof(vis));
				dfs(i, j, A[i][j], A[i][j-1], tam);
				res = max(res, tam);
			}
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (res >= n * n / 2) return cout << res << endl, 0;	

			if (A[i-1][j] != A[i][j]) {
				int tam = 0;	
				memset(vis, 0, sizeof(vis));
				dfs(i, j, A[i][j], A[i-1][j], tam);
				res = max(res, tam);
			}
		}
	}

	cout << res << endl;

    return(0);
}
