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

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<pair<int, int>>> g(n);

	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w; u--, v--;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}

	auto dfs = [&] (int in, int out) {
		vector<pair<int, int>> pai(n, {-1, -1}); pai[in] = {in, 0};
		stack<int> s; s.push(in);

		while (s.size()) {
			int u = s.top(); s.pop();

			for (auto [v, w] : g[u]) {
				if (pai[v].f != -1) continue;
				pai[v] = {u, w};
				s.push(v);
			}
		}

		if (pai[out].f == -1) return vector<int>(0);

		vector<int> res;
		for (int i = out; i != in; i = pai[i].f) {
			res.push_back(pai[i].s);
		}

		return res;
	};

	int q; cin >> q;
	while (q--) {
		int in, out, x;
		cin >> in >> out >> x; in--, out--;
		
		vector<int> opc = dfs(in, out);
		int tot = accumulate(opc.begin(), opc.end(), 0);
		x -= tot;
		
		if (x < 0) {
			cout << "No" << endl;
			continue;
		}

		vector<int> dp(x+1, INF);
		dp[0] = (int)opc.size();

		for (int i = 1; i < (int)opc.size(); i++) {
			for (int j = opc[i]*2; j <= x; j++) {
				dp[j] = min(dp[j], dp[j-opc[i]*2] + 2);
			}
		}

		if (dp[x] != INF) {
			cout << "Yes " << dp[x] << endl;
		} else {
			cout << "No" << endl;
		}
	}
}

int main()
{
    _;

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		if (i) cout << endl;
		solve();
	}
    
    return(0);
}
