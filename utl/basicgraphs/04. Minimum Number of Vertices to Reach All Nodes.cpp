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

	vector<vector<int>> g(n);
	vector<int> cont(n, 1), vis(n, 0);
	for (auto vi : edges)
		g[vi[0]].push_back(vi[1]), g[vi[1]].push_back(vi[0]);

	function<int(int)> dfs = [&] (int u) {
		vis[u] = 1;
		for (int v : g[u])
			if (!vis[v]) return cont[u] += dfs(v);	
		return 1;
	};

	for (int i = 0; i < n; i++)
		if (!vis[i])
			dfs(i);

	for (int i = 0; i < n; i++)
		if (cont[i] == n)
			return i;
    
    return(0);
}
