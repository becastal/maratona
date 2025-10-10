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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

int solve() {
	int n; cin >> n;
	vector<vector<int>> g(n);
	vector<int> cor(n);

	for (int& i : cor) cin >> i;
	//auto cor_ = cor;
	//sort(cor_.begin(), cor_.end());
	//cor_.erase(unique(cor_.begin(), cor_.end()), cor_.end());
	//for (int& i : cor) {
	//	i = lower_bound(cor_.begin(), cor_.end(), i) - cor_.begin();
	//}

	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int t = 0;
	vector<int> tin(n), tout(n), euler(n);
	vector<vector<int>> fins(n);
	function<void(int, int)> dfs = [&](int u, int p) {
		tin[u] = t, euler[t++] = u;
		for (int v : g[u]) if (v != p) {
			dfs(v, u);
		}
		fins[t-1].push_back(u);
		tout[u] = t-1;
	};
	dfs(0, -1);

	vector<int> res(n);
	ordered_set us;
	map<int, int> ult;
	for (int i = 0; i < n; i++) {
		if (ult.count(cor[euler[i]])) {
			us.erase(ult[cor[euler[i]]]);
		}
		us.insert(ult[cor[euler[i]]] = i);

		for (int u : fins[i]) {
			res[u] = (int)us.size() - us.order_of_key(tin[u]);
			//dbg(u);
		}
	}
	for (int i : res) cout << i << ' '; cout << endl;

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
