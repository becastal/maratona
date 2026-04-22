#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m; cin >> n >> m;

	int k; cin >> k;
	vector<int> L(k);
	for (int& u : L) {
		cin >> u; u--;
	}

	vector<vector<array<int, 2>>> G(n + m * m);
	vector<vector<int>> Reg(n), UReg(m), Cont(m, vector<int>(m));

	for (int i = 0; i < n; i++) {
		int nn; cin >> nn;
		Reg[i] = vector<int>(nn);
		for (int& j : Reg[i]) {
			cin >> j; j--;
			UReg[j].push_back(i);
		}

		for (int j = 0; j < nn; j++) {
			int u = Reg[i][j], v = Reg[i][(j + 1) % nn];
			if (u > v) swap(u, v);

			G[i].push_back({n + u * m + v, 1});
			G[n + u * m + v].push_back({i, 0});
		}
	}

	vector<int> Res(n);
	for (int u : L) {
		vector<int> D(n + m * m, LLONG_MAX);
		deque<int> Q;

		sort(all(UReg[u]));
		UReg[u].erase(unique(all(UReg[u])), UReg[u].end());

		for (int r : UReg[u]) {
			Q.push_front(r);
			D[r] = 0;
		}

		while (Q.size()) {
			int r1 = Q.front(); Q.pop_front();

			for (auto [r2, w] : G[r1]) if (D[r2] > D[r1] + w) {
				D[r2] = D[r1] + w;
				if (w) {
					Q.push_back(r2);
				} else {
					Q.push_front(r2);
				}
			}
		}


		for (int i = 0; i < n; i++) {
			Res[i] += D[i];
		}
	}

	auto it = min_element(all(Res));
	cout << *it << endl << it - Res.begin() + 1 << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

