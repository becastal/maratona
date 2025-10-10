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
	int n1, n2, m1, m2; cin >> n1 >> n2 >> m1 >> m2;
	
	vector<vector<int>> g1(n1), g2(n2);
	vector<int> in1(n1, 0), in2(n2, 0);
	for (int i = 0, u, v; i < m1; i++) {
		cin >> u >> v; u--, v--;
		g1[u].push_back(v);
		in1[v]++;
	}
	for (int i = 0, u, v; i < m2; i++) {
		cin >> u >> v; u--, v--;
		g2[u].push_back(v);
		in2[v]++;
	}

	auto f = [](int n, vector<int> in, vector<vector<int>> g) {
		vector<int> vis(n, 0);
		vector<bitset<3000>> dp(n);
		dp[0][0] = 1;

		function<void(int)> dfs = [&](int u) {
			vis[u] = 1;
			
			for (int v : g[u]) {
				dp[v] |= dp[u] << 1;	
				if (--in[v] == 0) dfs(v);
			}
		};

		for (int i = 0; i < n; i++) {
			if (!vis[i] and !in[i]) dfs(i);
		}

		return dp;
	};

	auto dp1 = f(n1, in1, g1).back();
	auto dp2 = f(n2, in2, g2).back();

	int q; cin >> q;
	while (q--) {
		int s; cin >> s;

		auto A = dp1;
		for (int i = s+1; i < 3000; i++) A[i] = 0;
		for (int i = 0; i < (s + 1) / 2; i++) {
			bool tmp = A[i];
			A[i] = A[s-i];
			A[s-i] = tmp;
		}
		
		cout << ((A & dp2).any() ? "Yes" : "No") << endl;
	}

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
