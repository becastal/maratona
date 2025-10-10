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
	vector<int> id, sz, cont;
	DSU(int n) : id(n), sz(n, 1), cont(n, 0) {
		iota(id.begin(), id.end(), 0);
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	void merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		if (sz[i] < sz[j]) swap(i, j);
		sz[i] += sz[j], id[j] = i;
		cont[i] |= cont[j];
	}
};

int main()
{
    _;

	int n, m; cin >> n >> m;
	vector<int> ruim(n, 0), ruins(m);

	DSU dsu(n);
	for (int& i : ruins) {
		cin >> i;
		ruim[i] = 1;
		dsu.cont[i] = 1;
	}

	vector<tuple<int, int, int>> ed(n-1);
	for (auto& [w, u, v] : ed) {
		cin >> u >> v >> w;
	}
	sort(ed.rbegin(), ed.rend());

	ll res = 0;
	for (auto [w, u, v] : ed) {
		int ui = dsu.find(u), vi = dsu.find(v);
		if (ui == vi) continue;

		if (dsu.cont[ui] and dsu.cont[vi]) {
			//cout << u << ' '<< v << endl;
			res += w;
		} else {
			dsu.merge(ui, vi);
		}
	}

	cout << res << endl;
    
    return(0);
}
