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
	setIO("revegetate");

	int n, m; cin >> n >> m;
	vector<vector<pair<int, int>>> g(n);
	for (int i = 0; i < m; i++) {
		char c; cin >> c;
		int u, v; cin >> u >> v; u--, v--;

		g[u].emplace_back(v, (c == 'D'));
		g[v].emplace_back(u, (c == 'D'));
	}

	int cont = 0;
	vector<int> cor(n, -1);
	function<int(int)> dfs = [&](int u) {
		for (auto [v, w] : g[u]) {
			if (cor[v] == -1) {
				cor[v] = cor[u] ^ w;
				if (!dfs(v)) return 0;
			}
			else if (cor[v] == cor[u] ^ !w) return 0;
		}

		return 1;
	};

	int res = 0;
	for (int i = 0; i < n; i++) {
		if (cor[i] != -1) continue;

		cor[i] = 0;
		if (!dfs(i)) return cout << 0 << endl, 0;	
		else res++, cont++;
	}	

	cout << '1' << string(res, '0') << endl;

    return(0);
}
