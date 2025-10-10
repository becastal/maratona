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
	int n, m, c; cin >> n >> m >> c;

	vector<ll> dp(n);
	for (ll& i : dp) cin >> i;

	vector<vector<pair<int, int>>> g(n);
	vector<int> vis(n, 0), in(n, 0);
	for (int i = 0, u, v, w; i < c; i++) {
		cin >> u >> v >> w; u--, v--;
		g[u].emplace_back(v, w);
		in[v]++;
	}

	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;

		for (auto [v, w] : g[u]) {
			dp[v] = max(dp[v], dp[u] + w);
			if (!--in[v]) dfs(v);
		}
	};

	for (int i = 0; i < n; i++) {
		if (!vis[i] and !in[i]) dfs(i);
	}

	for (ll i : dp) cout << i << endl;

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main() {
    _;
	setIO("timeline");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}

