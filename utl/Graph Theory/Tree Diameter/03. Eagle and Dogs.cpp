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
typedef pair<int, int> ii;

void solve() {
	int n; cin >> n;
	vector<vector<ii>> g(n);

	for (int i = 0, u, v, w; i < n-1; i++) {
		cin >> u >> v >> w; u--, v--;
		g[u].push_back(ii(v, w));
		g[v].push_back(ii(u, w));
	}

	auto dfs = [&] (int src, vector<ll>& d) {
		stack<int> s; s.push(src);
		d[src] = 0;
		
		ll longe = 0;
		int onde = 0;

		while (!s.empty()) {
			int u = s.top(); s.pop();

			if (d[u] > longe) {
				longe = d[u];
				onde = u;
			}

			for (auto [v, w] : g[u]) {
				if (d[v] != -1) continue;

				s.push(v);
				d[v] = d[u] + w;
			}
		}
		return pair<int, ll>(onde, longe);
	};

	vector<ll> da(n, -1), db(n, -1), dc(n, -1);
	dfs(dfs(dfs(0, da).f, db).f, dc);

	for (int i = 0; i < n; i++) {
		cout << max(db[i], dc[i]) << ' ';
	}
	cout << endl;
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
