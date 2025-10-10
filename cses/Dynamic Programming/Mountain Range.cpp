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
	vector<int> h(n);
	for (int& i : h) cin >> i;

	vector<vector<int>> g(n);
	vector<int> peso(n, 0), vis(n, 0), dp(n, 1);
	stack<int> s;
	for (int i = 0; i < n; i++) {
		while (s.size() and h[s.top()] <= h[i]) {
			s.pop();
		}

		if (s.size()) {
			g[s.top()].push_back(i);
			peso[i]++;
		}
		s.push(i);
	}

	while (s.size()) s.pop();
	for (int i = n-1; i >= 0; i--) {
		while (s.size() and h[s.top()] <= h[i]) {
			s.pop();
		}

		if (s.size()) {
			g[s.top()].push_back(i);
			peso[i]++;
		}
		s.push(i);
	}

	// agora eh caminho maximo na dag que criei

	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;

		for (int v : g[u]) {
			dp[v] = max(dp[v], dp[u] + 1);
			if (--peso[v] == 0) dfs(v);
		}
	};

	for (int i = 0; i < n; i++) {
		if (!vis[i] and !peso[i]) {
			dfs(i);
		}
	}
	cout << *max_element(dp.begin(), dp.end()) << endl;

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
