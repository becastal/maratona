#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, q; cin >> n >> q;

	vector<int> R(n);
	vector<set<int>> G(n);
	int res = n;

	while (q--) {
		int tp; cin >> tp;

		if (tp == 1) {
			int u, v; cin >> u >> v; u--, v--;
			res -= (++R[u] == 1);
			res -= (++R[v] == 1);
			G[u].insert(v);
			G[v].insert(u);
		} else {
			int u; cin >> u; u--;
			for (int v : G[u]) if (G[v].count(u)) {
				G[v].erase(u);
				res += (--R[u] == 0);
				res += (--R[v] == 0);
			}
			G[u].clear();
		}
		cout << res << endl;
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

