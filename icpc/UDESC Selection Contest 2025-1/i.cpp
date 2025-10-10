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
	vector<vector<int>> g(26);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 1; j < (int)s.size(); j++) {
			if (s[j-1]-'a' == s[j]-'a') continue;
			g[s[j-1]-'a'].push_back(s[j]-'a');
		}
	}

	n = 26;
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
	if (res.empty()) return cout << "NAO" << endl, 0;
	cout << "SIM" << endl;
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
