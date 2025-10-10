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
	setIO("mooyomooyo");

	int n, m = 10, k; cin >> n >> k;
	vector<string> a(n);
	for (auto& i : a) cin >> i;

	vector<pair<int, int>> movs = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
	auto valido = [&](int i, int j) { return i >= 0 and i < n and j >= 0 and j < m; };

	int ok = 1;
	while (ok) {
		ok = 0;

		vector<pair<int, int>> comp;
		vector<vector<int>> vis(n, vector<int>(m, 0));

		function<void(int, int)> dfs = [&](int ui, int uj) {
			comp.emplace_back(ui, uj);
			vis[ui][uj] = 1;

			for (auto [di, dj] : movs) {
				int vi = di + ui, vj = dj + uj;
				if (!valido(vi, vj) or vis[vi][vj] or a[vi][vj] != a[ui][uj]) continue;
				dfs(vi, vj);
			}
		};

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == '0' or vis[i][j]) continue;

				comp.clear();
				dfs(i, j);

				if (comp.size() >= k) {
					ok = 1;
					for (auto [i_, j_] : comp) {
						a[i_][j_] = '0';
					}
				}
			}
		}

		for (int j = 0; j < m; j++) {
			int w = n - 1;
			for (int i = n-1; i >= 0; i--) {
				if (a[i][j] != '0') {
					a[w--][j] = a[i][j];
				}
			}

			while (w >= 0) {
				a[w--][j] = '0';
			}
		}
	}

	for (auto i : a) {
		cout << i << endl;
	}

    return(0);
}
