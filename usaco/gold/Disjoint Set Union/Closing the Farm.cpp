#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

struct DSU {
	int mxcc;
	vector<int> id, sz;
	DSU(int n) : id(n), sz(n, 1), mxcc(1) {
		iota(id.begin(), id.end(), 0);
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	void merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		if (sz[i] < sz[j]) swap(i, j);
		sz[i] += sz[j], id[j] = i;
		mxcc = max(mxcc, sz[i]);
	}
};

int solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n);
	vector<int> Q(n);

	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int& i : Q) cin >> i, i--;
	reverse(all(Q));

	DSU dsu(n);
	vector<int> res(n), vivo(n, 0);
	for (int i = 0; i < n; i++) {
		int u = Q[i];
		vivo[u] = 1;
		for (int v : g[u]) {
			if (vivo[v]) dsu.merge(u, v);
		}
		res[i] = (dsu.mxcc == i + 1);
	}
	reverse(all(res));
	for (int i : res) cout << (i ? "YES" : "NO") << endl;

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main() {
    _;
	setIO("closing");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}

