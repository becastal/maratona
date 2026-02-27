#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int mod = 1e9+7;
int solve() {
	int n; cin >> n;

	vector<vector<int>> G(n);
	vector<int> P(n);
	for (int i = 0, l, r; i < n; i++) {
		cin >> l >> r;
		if (l == r and !l) continue;	
		l--, r--;
		G[i].push_back(l), G[i].push_back(r);
	}

	vector<int> T(n);
	function<int(int)> dfs = [&](int u) {
		int s = 1;
		for (int v : G[u]) {
			s += dfs(v);	
		}
		return T[u] = s;
	};
	dfs(0);

	for (int i = 0; i < n; i++) {
		T[i] = 2 * T[i] - 1;
	}

	function<void(int, int)> dfs2 = [&](int u, int p) {
		if (u) {
			T[u] += T[p];
			if (T[u] >= mod) {
				T[u] -= mod;
			}
		}
		for (int v : G[u]) {
			dfs2(v, u);
		}
	};
	dfs2(0, -1);

	for (int i = 0; i < n; i++) {
		cout << T[i] << " \n"[i==n-1];
	}

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

