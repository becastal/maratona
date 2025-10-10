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
	vector<string> A(n);
	for (auto& i : A) cin >> i;

	vector<vector<int>> g(26);
	for (int i = 0; i < n-1; i++) {
		string s = A[i], t = A[i+1];

		int j = 0;
		while (j < s.size() and j < t.size() and s[j] == t[j]) j++;

		if (j == t.size() and s.size() > t.size()) return cout << "Impossible" << endl, 0;

		if (j < s.size() and j < t.size()) {
			g[s[j] - 'a'].push_back(t[j] - 'a');
		}
	}

	auto topo_sort = [&](int n) {
		vector<int> ret(n, -1), vis(n, 0);
		
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

	auto res = topo_sort(26);
	if (res.empty()) return cout << "Impossible" << endl, 0;
	for (int i : res) cout << char('a' + i); cout << endl;

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
