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
	int n; cin >> n;
	vector<int> v(n);
	for (int& i : v) cin >> i, i--;

	vector<vector<int>> g(n);
	for (int i = 0; i < n; i++) {
		g[i].push_back(v[i]);
	}

	vector<int> vis(n, 0);
	auto dfs = [&] (int in) {
		stack<int> s; s.push(in);
		vis[in] = 1;

		int res = 0;
		while (s.size()) {
			int u = s.top(); s.pop();
			res++;

			for (int v : g[u]) {
				if (vis[v]) continue;
				s.push(v);
				vis[v] = 1;
			}
		}
		return res;
	};

	int res = 0;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			res += (dfs(i) - 1) / 2;
		}
	}
	cout << res << endl;
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
