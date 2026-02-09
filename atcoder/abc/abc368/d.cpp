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

	int n, k; cin >> n >> k;
	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	set<int> s;
	vector<int> v(k), cont(n, 0);	
	for (int& i : v) cin >> i, i--, s.insert(i);

	function<int(int, int)> dfs = [&](int u, int pai) {
		int soma = 0;
		for (int v : g[u]) {
			if (v != pai) {
				soma += dfs(v, u);
			}
		}
		return cont[u] = soma + s.count(u);
	};
	dfs(v[0], -1);

	int res = n;
	for (int i : cont) res -= !i;

	cout << res << endl;
    
    return(0);
}
