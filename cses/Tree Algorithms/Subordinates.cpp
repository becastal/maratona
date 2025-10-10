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
	vector<int> vis(n, 0), cont(n, 0);
	for (int i = 0, u; i < n - 1; i++) {
		cin >> u; u--;
		g[u].push_back(i + 1);
	}
 
	function<int(int)> dfs = [&](int u) {
		vis[u] = 1;
		cont[u] = (int)g[u].size();
		for (int v : g[u]) {
			if (!vis[v]) {
				cont[u] += dfs(v);
			}
		}
		return cont[u];
	};
	dfs(0);
 
	for (int i : cont) cout << i << ' ';
	cout << endl;
    
    return(0);
}
