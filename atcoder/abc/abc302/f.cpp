#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
	parece que vai virar grafo.

	se cada aresta for uma operacao entre sets,
	dai seria tipo bfs01 nesse grafo
*/

int solve() {
	int n, m; cin >> n >> m;
	vector<vector<array<int, 2>>> G(n + m);

	for (int i = 0, nn; i < n; i++) {
		cin >> nn;
		for (int j = 0, x; j < nn; j++) {
			cin >> x; x--;
			G[i + m].push_back({x, 0});
			G[x].push_back({i + m, 1});
		}
	}

	deque<int> Q; Q.push_back(0);
	vector<int> D(n + m, INT_MAX); D[0] = 0;

	while (Q.size()) {
		int u = Q.front(); Q.pop_front();

		for (auto [v, w] : G[u]) if (D[v] > D[u] + w) {
			D[v] = D[u] + w;
			if (w) {
				Q.push_back(v);
			} else {
				Q.push_front(v);
			}
		}
	}

//	for (int i = 0 ; i < m; i++) {
//		cout << D[i] << " \n"[i==m-1];
//	}
//	cout << "~" << endl;
//	for (int i = 0 ; i < n; i++) {
//		cout << D[i] << " \n"[i==n-1];
//	}

	cout << (D[m-1] == INT_MAX ? -1 : D[m-1] - 1) << endl;

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

