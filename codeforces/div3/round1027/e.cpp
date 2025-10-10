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
	vector<ll> a(n);
	for (ll& i : a) cin >> i;

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<ll> res(n);
    auto dfs = [&](auto& dfs, int u, int p, int c, ll pref, ll mn, ll mx) -> void {
		res[u] = c ? mx - pref : pref - mn;

        for (int v : g[u]) {
            if (v == p) continue;
            dfs(dfs, v, u, c ^ 1, pref + (c ? +a[v] : -a[v]), min(mn, pref), max(mx, pref));
        }
    };
    dfs(dfs, 0, -1, 0, a[0], 0LL, 0LL);

	for (ll i : res) cout << i << ' '; cout << endl;

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
