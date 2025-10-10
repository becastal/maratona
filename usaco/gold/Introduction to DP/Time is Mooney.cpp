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

int self_max(int& a, int b) {
	return a = max(a, b);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("time");

	const int Tmax = 1000;

	int n, m, c; cin >> n >> m >> c;
	vector<int> din(n);
	for (int& i : din) cin >> i;

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
	}

	vector dp(Tmax+1, vector<int>(n+1, -1));

	dp[0][0] = 0;
	int res = 0;
	for (int i = 0; i < Tmax; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == -1) continue;

			for (int v : g[j]) {
				self_max(dp[i+1][v], dp[i][j] + din[v]);
			}
		}
		self_max(res, dp[i][0] - (c * i * i));
	}


	cout << res << endl;

    return(0);
}
