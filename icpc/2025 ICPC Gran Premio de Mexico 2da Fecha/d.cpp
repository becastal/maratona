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
	vector<int> id, sz;
	DSU(int n) : id(n), sz(n, 1) {
		iota(id.begin(), id.end(), 0);
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	void merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		if (sz[i] < sz[j]) swap(i, j);
		sz[i] += sz[j], id[j] = i;
	}
};

int solve() {
	int n, m; cin >> n >> m;
	vector<int> A(n);
	map<int, vector<int>> E;

	for (int i = 0; i < n; i++) {
		cin >> A[i];
		E[A[i]].push_back(i);
	}

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	DSU dsu(n);
	vector<int> vivo(n, 0), res(n, -1);
	for (auto [e, V] : E) {
		for (int u : V) {
			vivo[u] = 1;
		}

		for (int u : V) {
			for (int v : g[u]) if (vivo[v]) {
				dsu.merge(u, v);
			}
		}

		for (int u : V) {
			res[u] = dsu.sz[dsu.find(u)];
		}
	}

	for (int i : res) cout << i << endl;

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
