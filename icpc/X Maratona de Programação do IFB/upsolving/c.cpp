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
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n);
	for (int i = 1, pi; i < n; i++) {
		cin >> pi; pi--;
		g[pi].push_back(i);
		g[i].push_back(pi);
	}

	vector<int> res, pega(n, 0);
	for (int i = 0, pi; i < m; i++) {
		cin >> pi; pi--;
		pega[pi] = 1;
	}

	function<int(int, int)> dfs = [&](int u, int p) {
		int cont = 0;
		for (int v : g[u]) {
			if (v == p) continue;
			cont += dfs(v, u);
		}

		if (cont >= 2 or pega[u]) res.push_back(u);
		return (cont + pega[u]) >= 1;
	};
	dfs(0, -1);

	sort(res.begin(), res.end());
	cout << res.size() << endl;
	for (int i = 0; i < (int)res.size(); i++) {
		cout << res[i]+1 << " \n"[i==(int)res.size()-1];
	}

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
