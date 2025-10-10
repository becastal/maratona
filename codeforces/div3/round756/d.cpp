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
	vector<vector<int>> g(n);
	vector<int> b(n);
	int U = -1;
	for (int i = 0; i < n; i++) {
		cin >> b[i]; b[i]--;

		if (i == b[i]) U = i;
		g[i].push_back(b[i]);
		g[b[i]].push_back(i);
	}

	vector<int> pos(n), p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i]; p[i]--;
		pos[p[i]] = i;	
	}

	int ok = 1;
	function<int(int, int)> dfs = [&](int u, int pa) {
		int agr = pos[u];
		for (int v : g[u]) {
			if (v == pa) continue;	
			agr = min(agr, dfs(v, u));
		}
		ok &= (pos[u] <= agr);
		return agr;
	};
	
	dfs(U, -1);
	if (!ok) return cout << -1 << endl, 0;

	vector<int> d(n, 0);
	for (int i = 1; i < n; i++) {
		d[p[i]] = d[p[i-1]] + 1;
	}

	for (int i = 0; i < n; i++) {
		cout << d[i] - d[b[i]] << " \n"[i==n-1];
	}

	return 0;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}
