#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m, k; cin >> n >> m >> k;

	vector<array<int, 2>> D(n, {INT_MAX, INT_MAX});
	vector<array<int, 2>> quem(n, {-1, -1});
	queue<array<int, 2>> Q;

	for (int i = 0, u; i < k; i++) {
		cin >> u; u--;
		Q.push({u, 0});	
		D[u][0] = 0;
		quem[u][0] = u;
	}

	vector<vector<int>> G(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

    while (Q.size()) {
        auto [v, p] = Q.front(); Q.pop();

        if (!p) {
            for (int u : G[v]) {
                if (D[u][0] == INT_MAX) {
                    D[u][0] = D[v][0] + 1;
                    quem[u][0] = quem[v][0];
                    Q.push({u, 0});
                }

                if (D[u][0] != INT_MAX and D[u][1] == INT_MAX and quem[u][0] != quem[v][0]) {
                    D[u][1] = D[v][0] + 1;
                    quem[u][1] = quem[v][0];
                    Q.push({u, 1});
                }
            }
        } else {
            for (int u : G[v]) {
                if (D[u][1] == INT_MAX) {
                    D[u][1] = D[v][1] + 1;
                    quem[u][1] = quem[v][1];
                    Q.push({u, 1});
                }
            }
        }
    }

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			if (D[i][j] == INT_MAX) D[i][j] = -1;
		}
	}

	for (int i = 0; i < n; i++) {
		if (D[i][0] == INT_MAX) cout << -1 << " \n"[i==n-1];
		else {
			cout << (D[i][0] ? D[i][0] : D[i][1]) << " \n"[i==n-1];
		}
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

