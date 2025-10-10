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
	int cont;
	vector<int> id;
	DSU(int n) : id(n), cont(n) {
		iota(id.begin(), id.end(), 0);
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	void merge(int i, int j, int w) {
		if ((i = find(i)) == (j = find(j))) return;
		id[j] = i;
		cont--;
	}
};

int main()
{
    _;

	int n, m; cin >> n >> m;
	vector<tuple<ll, int, int>> ed(m);
	for (auto& [w, u, v] : ed) {
		cin >> u >> v >> w; u--, v--;
	}
	sort(ed.begin(), ed.end());

	ll res = LINF;
	for (int i = 0; i < m; i++) {
		DSU dsu(n);

		for (int j = i; j < m; j++) {
			auto [w, u, v] = ed[j];
			dsu.merge(u, v, w);
			if (dsu.cont == 1) res = min(res, get<0>(ed[j]) - get<0>(ed[i]));
		}
	}

	if (res == LINF) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl << res << endl;
	}
    
    return(0);
}
