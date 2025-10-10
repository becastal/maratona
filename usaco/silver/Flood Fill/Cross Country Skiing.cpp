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
	setIO("ccski");

	int n, m; cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (auto& i : a) for (auto& j : i) cin >> j;	

	vector<pair<int, int>> pos;
	for (int i = 0; i < n; i++) {
		for (int j = 0, x; j < m; j++) {
			cin >> x;
			if (x) pos.emplace_back(i, j);	
		}
	}

	auto valido = [&](int i, int j) { return i >= 0 and i < n and j >= 0 and j < m; };
	vector<pair<int, int>> movs = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

	auto da = [&](int mid) {
		vector<vector<int>> vis(n, vector<int>(m, 0));

		function<void(int, int)> dfs = [&](int ui, int uj) {
			//printf("u: (%d, %d)\n", ui, uj);
			vis[ui][uj] = 1;
			for (auto [di, dj] : movs) {
				int vi = ui + di, vj = uj + dj;	
				if (!valido(vi, vj) or abs(a[vi][vj] - a[ui][uj]) > mid or vis[vi][vj]) continue;
				dfs(vi, vj);
			}
		};

		dfs(pos[0].f, pos[0].s);
		for (auto [i, j] : pos) {
			if (!vis[i][j]) return 0;
		}

		//for (auto i : vis) {
		//	for (int j : i) {
		//		cout << j;
		//	}
		//	cout << endl;
		//}
		//cout << endl;

		return 1;
	};

	int l = 0, r = 1000000010, res = r;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		//dbg(mid);

		if (da(mid)) {
			r = mid-1;
			res = mid;
		} else {
			l = mid+1;
		}
	}
	cout << res << endl;

    return(0);
}
