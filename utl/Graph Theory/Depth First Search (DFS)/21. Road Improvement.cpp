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

int main()
{
    _;

	int n; cin >> n;
	vector<vector<pair<int, int>>> g(n);
	vector<int> cont(n, 0);

	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		g[u].emplace_back(v, i+1);
		g[v].emplace_back(u, i+1);
		cont[v]++, cont[u]++;
	}

	int k = 0;
	vector<vector<int>> res((int)2e5+10);
	function<void(int, int, int)> dfs = [&](int u, int pai, int c) {
		int agr = 0;

		for (auto [v, i] : g[u]) {
			if (v == pai) continue;
			agr++;
			if (agr == c) agr++;
			k = max(k, agr);
			res[agr].push_back(i);
			dfs(v, u, agr);
		}
	};

	dfs(1, -1, 0);
	cout << k << endl;
	for (int i = 1; i <= k; i++) {
		cout << res[i].size() << ' ';
		for (int i : res[i]) cout << i << ' '; cout << endl;
	}
    
    return(0);
}
