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

void solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> ok(n, 0);
	queue<pair<int, int>> q;
	for (int i = 0, u, x; i < k; i++) {
		cin >> u >> x; u--;
		ok[u] = 1;
		q.emplace(u, x);
	}

	while (q.size()) {
		auto [u, x] = q.front(); q.pop();

		if (!x) continue;
		for (int v : g[u]) {
			if (!ok[v]) {
				ok[v] = 1;
				q.emplace(v, x-1);
			}
		}
	}

	int res = 1;
	for (int i : ok) res &= i;
	cout << (res ? "Yes" : "No") << endl;
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
