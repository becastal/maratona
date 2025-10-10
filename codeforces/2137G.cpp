#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m, q; cin >> n >> m >> q;

	vector<vector<int>> G(n), G_(n);
	vector<int> cont(n, 0);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G_[v].push_back(u);
		cont[u]++;
	}


	vector<int> R(n, 1), B(n);
	
	while (q--) {
		int tp, u; cin >> tp >> u; u--;

		if (tp == 2) {
			cout << (R[u] ? "YES" : "NO") << endl;
		} else {
			queue<array<int, 2>> Q;

			if (R[u]) Q.push({u, 0});
			if (!B[u]) {
				Q.push({u, 1});
				B[u] = 1;
			}

			while (Q.size()) {
				auto [a, agr] = Q.front(); Q.pop();

				if (agr) {
					for (int b : G_[a]) {
						if (--cont[b] == 0) {
							Q.push({b, 0});
						}
					}
				} else {
					if (!R[a]) continue;
					R[a] = 0;

					for (int b : G_[a]) {
						if (B[b]) continue;
						B[b] = 1;
						Q.push({b, 1});
					}
				}
			}
		}
	}

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

