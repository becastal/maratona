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
	int n, m, k; cin >> n >> m >> k;
	
	vector<string> A(n);
	map<string, int> M;
	vector<pair<string, int>> B(m);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
		M[A[i]] = i;
	}

	for (auto& [a, b] : B) cin >> a >> b, b--;

	vector<vector<int>> g(n);
	for (auto& [s, pos] : B) {
		int ok = 0;
		for (int mask = 0; mask < (1 << k); mask++) {
			string t = s;
			for (int i = 0; i < k; i++) {
				if (mask & (1 << i)) t[i] = '_';
			}

			if (M.count(t)) {
				if (pos != M[t]) g[pos].push_back(M[t]);
				else ok = 1;
			}
		}

		if (!ok) return cout << "No" << endl, 0;
	}

	auto topo_sort = [&]() {
		vector<int> ret(n,-1), vis(n,0);
		
		int pos = n-1, dag = 1;
		function<void(int)> dfs = [&](int v) {
			vis[v] = 1;
			for (auto u : g[v]) {
				if (vis[u] == 1) dag = 0;
				else if (!vis[u]) dfs(u);
			}
			ret[pos--] = v, vis[v] = 2;
		};

		for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);

		if (!dag) ret.clear();	
		return ret;
	};

	auto res = topo_sort();
	if (res.empty()) return cout << "NO" << endl, 0;

	cout << "YES" << endl;
	for (int i : res) cout << i + 1 << ' '; cout << endl;

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
