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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("gates");

	int N = 4000;
	vector<vector<int>> vis(N, vector<int>(N, 0)), ruim(N, vector<int>(N, 0));

	map<char, pair<int, int>> mov = {
		{'N', {-1, 0}},
		{'S', {1, 0}},
		{'E', {0, 1}},
		{'W', {0, -1}}
	};

	int n; cin >> n;
	string s; cin >> s;

	int ui = 2010, uj = 2010;
	for (auto c : s) {
		auto [di, dj] = mov[c];

		ruim[ui + di][uj + dj] = ruim[ui + 2 * di][uj + 2 * dj] = 1;
		ui += 2 * di;
		uj += 2 * dj;
	}
	
	auto valido = [&](int i, int j) { return i >= 0 and i < N and j >= 0 and j < N; };
	vector<pair<int, int>> movs = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

	function<void(int, int)> dfs = [&](int ui_, int uj_) {
		stack<pair<int, int>> s;
		s.emplace(ui_, uj_);
		vis[ui_][uj_] = 1;

		while (s.size()) {
			auto [ui, uj] = s.top(); s.pop();

			for (auto [di, dj] : movs) {
				int vi = ui + di, vj = uj + dj;	
				if (valido(vi, vj) and !vis[vi][vj] and !ruim[vi][vj]) {
					vis[vi][vj] = 1;
					s.emplace(vi, vj);
				}
			}
		}
		//for (auto [di, dj] : movs) {
		//	int vi = ui + di, vj = uj + dj;	
		//	if (valido(vi, vj) and !vis[vi][vj] and !ruim[vi][vj]) dfs(vi, vj);
		//}
	};
	
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!vis[i][j] and !ruim[i][j]) {
				res++;
				dfs(i, j);	
			}
		}
	}
	cout << res-1 << endl;

    return(0);
}
