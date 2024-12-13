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

const int mod = 998244353;

int main()
{
    _;

	int n, m, k; cin >> n >> m >> k;
	vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; i++) {
		g[i].push_back(i+1);
	}
	g[n-1].push_back(0);

	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
	}

	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;
	};
    
    return(0);
}
