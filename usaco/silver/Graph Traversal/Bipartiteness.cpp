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

	vector<vector<int>> g(n);
	vector<int> cor(n, -1), cont(n, 0), tp(2, 0);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
		cont[u]++, cont[v]++;
	}

	function<bool(int, int)> dfs = [&] (int u, int c) {
		cor[u] = c; tp[c]++;
		for (int v : g[u]) {
			if (cor[v] == -1) {
				if (!dfs(v, !c)) return 0;
			} else if (cor[v] == c) return 0;
		}
		return 1;
	};
	
	for (int i = 0; i < n; i++) {
		if (cor[i] == -1) {
			assert(dfs(i, 0));
		}
	}

	ll res = 0;
	for (int i = 0; i < n; i++) {
		if (cor[i]) continue;
		
		res += tp[1] - cont[i];
		// da pra ligar e manter bipartido com todos os uns que eu nao to ligado
	}
	cout << res << endl;
    
    return(0);
}
