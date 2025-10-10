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
	vector<int> a(n);
	for (int& i : a) cin >> i;

	vector<vector<int>> g(n);
	for (int i = 1, si; i < n; i++) {
		cin >> si; si--;
		g[i].push_back(si);	
		g[si].push_back(i);
	}

	vector<ll> sub(n, 0);
	function<ll(int, int)> dfs1 = [&](int u, int p) {
		ll s = a[u];
		for (int v : g[u]) {
			if (v == p) continue;
			s += dfs1(v, u);
		}
		return sub[u] = s;
	};
	dfs1(0, -1);

	vector<ll> dp(n, 0);
	function<ll(int ,int)> dfs2 = [&](int u, int p) {
		ll s = 0;
		for (int v : g[u]) {
			if (v == p) continue;
			s += dfs2(v, u);
		}
		return dp[u] = max(sub[u], s);	
	};
	dfs2(0, -1);

	cout << dp[0] << endl;

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
