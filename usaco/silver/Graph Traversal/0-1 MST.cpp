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
	vector<set<int>> g_(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g_[u].emplace(v);
		g_[v].emplace(u);
	}

	set<int> unvis;
	for (int i = 0; i < n; i++) {
		unvis.emplace(i);
	}

	function<void(int)> dfs = [&](int uu) {
		stack<int> s; s.push(uu);

		while (s.size()) {
			int u = s.top(); s.pop();
			int ult = -1;
			for (int v : g_[u]) {
				auto it = unvis.upper_bound(ult);
				while (it != unvis.end() && *it < v) {
					int w = *it;
					it = unvis.erase(it);
					s.push(w);
				}
				ult = v;
			}

			if (ult < n - 1) {
				auto it = unvis.upper_bound(ult);
				while (it != unvis.end()) {
					int w = *it;
					it = unvis.erase(it);
					s.push(w);
				}
			}
		}
	};

	int cc = 0;
	while (unvis.size()) {
		int u = *unvis.begin();
		unvis.erase(unvis.begin());
		dfs(u);
		cc++;
	}

	cout << cc - 1 << endl;

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
