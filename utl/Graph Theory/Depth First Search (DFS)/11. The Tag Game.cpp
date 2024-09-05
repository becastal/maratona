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

	int n, x; cin >> n >> x; x--;

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	auto dfs = [&](int src) {
		stack<int> s; s.push(src);
		vector<int> d(n, -1); d[src] = 0;
		
		while (!s.empty()) {
			int u = s.top(); s.pop();
			for (int v : g[u]) {
				if (d[v] != -1) continue;

				d[v] = d[u] + 1;
				s.push(v);
			}
		}
		return d;
	};

	auto da = dfs(0), db = dfs(x);

	int res = 0;
	for (int i = 0; i < n; i++) {
		if (db[i] < da[i]) {
			res = max(res, da[i]*2);
		}
	}

	cout << res << endl;
    
    return(0);
}
