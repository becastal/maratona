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
	setIO("mootube");

	int n, q; cin >> n >> q;
	vector<vector<pair<int, int>>> g(n);

	for (int i = 0, u, v, w; i < n-1; i++) {
		cin >> u >> v >> w; u--, v--;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}

	function<int(int, int, int)> dfs = [&](int u, int p, int mn) {
		int s = 0;
		for (auto [v, w] : g[u]) {
			if (v == p or w < mn) continue;	
			s += dfs(v, u, mn);
		}
		return (p != -1) + s;
	};

	while (q--) {
		int k, u; cin >> k >> u; u--;
		cout << dfs(u, -1, k) << endl;
	}

    return(0);
}
