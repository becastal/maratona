#include <bits/stdc++.h>
//#define f first
//#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("");

	int n; cin >> n;
	const int N = pow(3, 9);

	vector<vector<string>> M(n, vector<string>(n));
	int ini, inj;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			M[i][j] = "   ";
			for (int k = 0; k < 3; k++) {
				cin >> M[i][j][k];
			}
			if (M[i][j] == "BBB") {
				ini = i, inj = j;
				M[i][j] = "...";
			}
		}
	}

	vector<int> p3 = {1};
	for (int i = 0; i < 10; i++) {
		p3.push_back(p3.back() * 3);
	}

	vector<vector<vector<int>>> vis(n, vector<vector<int>>(n, vector<int>(N, 0)));
	vector<int> tab_vis(N, 0);
	vector<pair<int, int>> movs = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
	vector<tuple<int, int, int>> pos_ganha {
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8},
		{0, 3, 6},
		{1, 4, 7},
		{2, 5, 8},
		{0, 4, 8},
		{2, 4, 6},
	};

	auto ganho = [&](int x) {
		for (auto [a, b, c] : pos_ganha) {
			int a_ = x / p3[a] % 3;
			int b_ = x / p3[b] % 3;
			int c_ = x / p3[c] % 3;
			if ((a_ == 2 and b_ == 1 and c_ == 1) or
				(a_ == 1 and b_ == 1 and c_ == 2)) return 1;
		}
	
		return 0;
	};
	auto valido = [&](int i, int j) { return i >= 0 and i < n and j >= 0 and j < n; };
	function<void(int, int, int)> dfs = [&](int ui, int uj, int tab) {
		vis[ui][uj][tab] = 1;
		tab_vis[tab] = 1;
		if (ganho(tab)) return;

		for (auto [di, dj] : movs) {
			int vi = ui + di, vj = uj + dj;
			if (!valido(vi, vj) || M[vi][vj] == "###") continue;

			if (M[vi][vj] == "...") {
				if (!vis[vi][vj][tab]) dfs(vi, vj, tab);
			} else {
				int pos = (M[vi][vj][1] - '1') * 3 + (M[vi][vj][2] - '1');

				if ((tab / p3[pos]) % 3 != 0) {
					if (!vis[vi][vj][tab]) dfs(vi, vj, tab);
					continue;
				}
				int tab_  = tab + (M[vi][vj][0] == 'M' ? 2 : 1) * p3[pos];

				if (!vis[vi][vj][tab_]) dfs(vi, vj, tab_);
			}
		}
	};

	dfs(ini, inj, 0);

	int res = 0;
	for (int i = 0; i < N; i++) {
		if (!tab_vis[i]) continue;
		res += ganho(i);
	}
	cout << res << endl;

    return(0);
}
