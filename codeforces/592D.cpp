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

	vector<vector<int>> G(n);
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	vector<int> A(m), S(n, 0);
	for (int& i : A) {
		cin >> i; i--;
		S[i] = 1;
	}
	if (m == 1) return cout << A[0] + 1 << endl << 0 << endl, 0;

	vector<int> D(n, 0);
	function<int(int, int)> dfs = [&](int u, int p) {
		for (int v : G[u]) if (v != p) {
			D[v] = D[u] + 1;
			S[u] += dfs(v, u);
		}
		return S[u];
	};
	dfs(A[0], -1);


	auto dist = [&](int in) {
		int dres = 0, ures = in;
		function<void(int, int, int)> dfs = [&](int u, int p, int d) {
			if (dres < d or (dres == d and u < ures)) {
				dres = d;
				ures = u;
			}
			for (int v : G[u]) if (v != p and S[v]) {
				dfs(v, u, d + 1);
			}
		};
		dfs(in, -1, 0);
		return make_pair(ures, dres);
	};


	auto [a, da] = dist(A[0]);
	auto [b, db] = dist(a);

	cout << min(a, b) + 1 << endl;
	int nn = n - count(all(S), 0);
	cout << 2LL * (nn - 1) - dist(dist(A[0]).f).s << endl;

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
