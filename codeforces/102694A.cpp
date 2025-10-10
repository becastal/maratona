#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n; cin >> n;

	vector<vector<int>> G(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);	
		G[v].push_back(u);	
	}

	auto diam = [&](int in) {
		int a = -1, b;
		function<void(int, int, int)> dfs = [&](int u, int p, int d) {
			if (d > a) {
				a = d;
				b = u;
			}
			for (int v : G[u]) if (v != p) {
				dfs(v, u, d+1);	
			}
		};
		dfs(in, -1, 0);
		return pair<int, int>(a, b);
	};

	cout << 3 * diam(diam(0).s).f << endl;

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
