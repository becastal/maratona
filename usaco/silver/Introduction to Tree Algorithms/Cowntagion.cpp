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
	setIO("");

	int n; cin >> n;
	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	function<int(int, int)> dfs = [&](int u, int p) {
		int fil = g[u].size() - (u ? 1 : 0);
		int agr = 1, s = 0;
		while (agr < fil + 1) agr <<= 1, s++;
		for (int v : g[u]) {
			if (v == p) continue;
			s += dfs(v, u) + 1;
		}

		return s;
	};
	cout << dfs(0, -1) << endl;

    return(0);
}
