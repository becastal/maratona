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

struct DSU {
	vector<int> id, sz, res, maxH;
	vector<vector<int>> Q;
	DSU(int n) : id(n), sz(n, 1), Q(n), res(n, -1), maxH(n, 0) {
		iota(all(id), 0);
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	void merge(int a, int b, int t) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (Q[a].size() < Q[b].size()) swap(a, b);
		for (int u : Q[b]) {
			if (maxH[a] > maxH[u]) {
				res[u] = t;
			} else {
				Q[a].push_back(u);
			}
		}
		Q[b].clear();

		id[b] = a;
		sz[a] += sz[b];
		maxH[a] = max(maxH[a], maxH[b]);
	}
};

int solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> H(n, vector<int>(m));

	map<int, vector<pair<int, int>>> M;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> H[i][j];
			M[-H[i][j]].emplace_back(i, j);
		}
	}

	DSU dsu(n*m);
	vector<pair<int, int>> movs = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
	vector<vector<int>> vivo(n, vector<int>(m, 0));
	for (auto [t_, V] : M) {
		int t = -t_;
		for (auto [ui, uj] : V) {
			vivo[ui][uj] = 1;
			dsu.maxH[ui * m + uj] = t;
		}

		for (auto [ui, uj] : V) {
			int zero = 0;
			for (auto [di, dj] : movs) {
				int vi = ui + di, vj = uj + dj;
				if (vi < 0 or vj < 0 or vi >= n or vj >= m or !vivo[vi][vj]) continue;
					
				if (dsu.maxH[dsu.find(vi * m + vj)] > t) {
					zero = 1;
					break;
				}
			}

			if (zero) {
				dsu.res[ui * m + uj] = 0;
			} else {
				dsu.Q[dsu.find(ui * m + uj)].push_back(ui * m + uj);
			}
		}

		for (auto [ui, uj] : V) for (auto [di, dj] : movs) {
			int vi = ui + di, vj = uj + dj;
			if (vi < 0 or vj < 0 or vi >= n or vj >= m or !vivo[vi][vj]) continue;
			dsu.merge(ui * m + uj, vi * m + vj, t);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dsu.res[i * m + j] == -1) dsu.res[i * m + j] = H[i][j];
			cout << dsu.res[i * m + j] << " \n"[j == m-1];
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
