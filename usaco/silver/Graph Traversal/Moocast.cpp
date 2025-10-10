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
	setIO("moocast");

	int n; cin >> n;
	vector<pair<int, int>> pos(n);
	for (auto& [x, y] : pos) cin >> x >> y;

	auto da = [&](ll m) {
		vector<vector<int>> g(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				auto [xi, yi] = pos[i];
				auto [xj, yj] = pos[j];
				if (1LL * (xi - xj) * (xi - xj) + (yi - yj) * (yi - yj) > m) continue;
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}

		vector<int> vis(n, 0);
		function<void(int)> dfs = [&](int u) {
			vis[u] = 1;
			for (int v : g[u]) {
				if (vis[v]) continue;
				dfs(v);
			}
		};
		dfs(0);

		return count(vis.begin(), vis.end(), 0) == 0;
	};

	ll l = 0, r = 1e15, res = r;
	while (l <= r) {
		int m = l + (r - l) / 2;

		if (da(m)) {
			r = m-1;
			res = m;
		} else {
			l = m+1;
		}
	}
	cout << res << endl;

    return(0);
}
