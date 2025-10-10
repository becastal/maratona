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

int solve() {
	int n; cin >> n;
	
	int cont = 0;
	vector<int> p(n), res(n, -1), vis(n, 0);
	for (int& i : p) cin >> i, i--;

	function<int(int)> dfs = [&](int u) {
		vis[u] = 1;
		cont++;
		if (!vis[p[u]]) return res[u] = dfs(p[u]);
		return res[u] = cont;
	};

	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		cont = 0;
		dfs(i);
	}

	for (int i : res) cout << i << ' '; cout << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
