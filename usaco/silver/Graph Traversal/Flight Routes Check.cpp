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
	int n, m, t = 0; cin >> n >> m;
	vector<vector<int>> g(n), repr(n);
	vector<pair<int, int>> ed(m);
	for (auto& [u, v] : ed) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
	}

	vector<int> vis(n, 0), comp(n), id(n), cont(n, 0);
	stack<int> s;

	function<int(int, int&)> dfs = [&](int i, int& t) {
		int lo = id[i] = t++;
		s.push(i);
		vis[i] = 2;

		for (int j : g[i]) {
			if (!vis[j]) lo = min(lo, dfs(j, t));
			else if (vis[j] == 2) lo = min(lo, id[j]);
		}

		if (lo == id[i]) while (1) {
			int u = s.top(); s.pop();
			vis[u] = 1, comp[u] = i, cont[comp[u]] = 1;
			repr[comp[u]].push_back(u);
			if (u == i) break;
		}

		return lo;
	};

	for (int i = 0; i < n; i++) if (!vis[i]) dfs(i, t);
	if (count(cont.begin(), cont.end(), 1) == 1) return cout << "YES" << endl, 0;

	vector<int> in(n, 0), out(n, 0);
	for (auto [u, v] : ed) {
		if (comp[u] != comp[v]) {
			out[comp[u]]++;
			in[comp[v]]++;
		}
	}

	int a = -1, b = -1;
	for (int i = 0; i < n; i++) {
		if (!cont[i]) continue;
		if (!out[i] and a == -1) a = i;	
		if (!in[i] and b == -1) b = i;
	}

	if (a == b) {
		for (int i = 0; i < n; i++) {
			if (!cont[i]) continue;
			if (!out[i] and i != a) {
				a = i;
				break;
			}
			if (!in[i] and i != b) {
				a = i;
				break;
			}
		}
	}

	cout << "NO" << endl;
	cout << repr[a][0]+1 << ' ' << repr[b][0]+1 << endl;

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
