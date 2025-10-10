#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = INT_MAX;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

struct DSU {
	vector<int> id, sz, mn;
	DSU(int n) : id(n), sz(n, 1), mn(n, INF) {
		iota(id.begin(), id.end(), 0);
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	void merge(int i, int j, int w) {
		if ((i = find(i)) == (j = find(j))) {
			mn[i] = min(mn[i], w);
			return;
		}
		if (sz[i] < sz[j]) swap(i, j);
		sz[i] += sz[j], id[j] = i;
		mn[i] = min({mn[i], mn[j], w});
	}
};

int solve() {
	int n, m; cin >> n >> m;

	vector<tuple<int, int, int>> E(m);
	for (auto& [w, u, v] : E) cin >> v >> u >> w, u--, v--;
	sort(all(E));

	DSU dsu(n);
	int res = INF;
	for (auto [w, u, v] : E) {
		dsu.merge(u, v, w);
		if (dsu.find(0) == dsu.find(n-1)) res = min(res, w + dsu.mn[dsu.find(0)]);
	}
	cout << res << endl;

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
