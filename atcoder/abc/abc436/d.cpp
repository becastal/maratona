#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
const int INF = 1e9+10;

int solve() {
	int n, m; cin >> n >> m;
	
	vector<vector<array<int, 2>>> G(n * m + 26);
	vector<vector<char>> A(n, vector<char>(m));

	const vector<array<int, 2>> movs = {
		{-1, 0}, 
		{0, -1}, 
		{1, 0}, 
		{0, 1}
	};
	auto valido = [&](int i, int j) {
		return i >= 0 and j >= 0 and i < n and j < m and A[i][j] != '#';
	};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
			if (A[i][j] == '#') continue;
			for (auto [di, dj] : movs) {
				if (valido(i + di, j + dj)) {
					G[i * m + j].push_back({(i + di) * m + (j + dj), 1});
					G[(i + di) * m + (j + dj)].push_back({i * m + j, 1});
				}
			}
			if (A[i][j] >= 'a' and A[i][j] <= 'z') {
				G[i * m + j].push_back({n * m + (A[i][j] - 'a'), 0});
				G[n * m + (A[i][j] - 'a')].push_back({i * m + j, 1});
			}
		}
	}

	vector<int> D(n * m + 26, INF); D[0] = 0;
	deque<int> Q; Q.push_front(0);

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

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << D[i * m + j] << " \n"[j==m-1];
	//	}
	//}

	int res = D[(n-1) * m + (m-1)];
	cout << (res == INF ? -1 : res) << endl;

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

