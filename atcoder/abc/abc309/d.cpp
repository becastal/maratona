#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int na, nb, m; cin >> na >> nb >> m;
	vector<vector<int>> Ga(na), Gb(nb);

	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		if (u < na and v < na) {
			Ga[u].push_back(v);
			Ga[v].push_back(u);
		} else {
			u -= na, v -= na;
			Gb[u].push_back(v);
			Gb[v].push_back(u);
		}
	}

	auto bfs = [](int n, int in, vector<vector<int>>& G) {
		vector<int> D(n, -1); D[in] = 0;
		queue<int> Q; Q.push(in);

		while (Q.size()) {
			int u = Q.front(); Q.pop();
			
			for (int v : G[u]) if (D[v] == -1) {
				D[v] = D[u] + 1;
				Q.push(v);
			}
		}

		return *max_element(all(D));
	};

	cout << bfs(na, 0, Ga) + 1 + bfs(nb, nb-1, Gb) << endl;

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

