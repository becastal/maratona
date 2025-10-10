#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, a, b; cin >> n >> a >> b;
	vector vis(2, vector<int>(n+1, 0));

	int res = 0;
	function<void(int, int)> dfs = [&](int k, int u) {
		vis[k][u] = 1;
		res = max(res, u);

		for (int v : {u + a, u + b}) if (v <= n and !vis[k][v]) {
			dfs(k, v);
		}

		if (!k and u) {
			int v = u / 2;
			if (!vis[1][v]) dfs(1, v);
		}
	};
	dfs(0, 0);
	cout << res << endl;

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main() {
    _;
	setIO("feast");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}

