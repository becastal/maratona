#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
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

	vector<array<int, 4>> ed(m);
	DSU dsu(n);

	int cont = 0;
	for (auto& [w, u, v, id] : ed) cin >> u >> v >> w, u--, v--, id = cont++;
	sort(ed.begin(), ed.end());

	vector<int> res(m, 0);
	for (int l = 0, r; l < m; l = r) {
		r = l + 1;

		while (r < m and ed[l][0] == ed[r][0]) {
			r++;
		}

		for (int i = l; i < r; i++) {
			res[ed[i][3]] = dsu.find(ed[i][1]) != dsu.find(ed[i][2]);
		}

		for (int i = l; i < r; i++) {
			dsu.merge(ed[i][1], ed[i][2]);
		}
	}

	for (int i : res) {
		cout << (i ? "YES" : "NO") << endl;
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
