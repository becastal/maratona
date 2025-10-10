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
	int n, m; cin >> n >> m;

	vector<int> A(n), P(m);
	vector<vector<int>> G(n);

	for (int& i : A) cin >> i;
	for (int i = 0; i < m; i++) {
		cin >> P[i]; P[i]--;
		G[P[i]].push_back(P[i] + 1);
		G[P[i] + 1].push_back(P[i]);
	}

	vector<int> vis(n, 0), cc;
	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;
		cc.push_back(u);

		for (int v : G[u]) if (!vis[v]) {
			dfs(v);
		}
	};

	for (int u = 0; u < n; u++) if (!vis[u]) {
		cc.clear();
		dfs(u);
		
		for (int i = 0; i < (int)cc.size(); i++) {
			for (int j = i+1; j < (int)cc.size(); j++) {
				if (A[cc[i]] > A[cc[j]]) swap(A[cc[i]], A[cc[j]]);	
			}
		}
	}

	return cout << (is_sorted(all(A)) ? "YES" : "NO") << endl, 0;

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
