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
	vector<set<int>> g(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i]; a[i]--;
		g[i].emplace(a[i]);
		g[a[i]].emplace(i);
	}

	int agr = 0, linha = 0, cc = 0;
	vector<int> vis(n, 0);
	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;
		agr |= (g[u].size() == 1);
		for (int v : g[u]) {
			if (vis[v]) continue;
			dfs(v);
		}
	};

	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		agr = 0;
		dfs(i);
		linha += agr;
		cc++;
	}

	cout << (cc - linha) + min(1, linha) << ' ' << cc << endl;

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
