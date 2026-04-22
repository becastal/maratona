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
	int res;
	vector<int> id, sz;
	DSU(int n) : id(n), sz(n, 1), res(0) {
		iota(id.begin(), id.end(), 0);
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	void merge(int i, int j, int w) {
		if ((i = find(i)) == (j = find(j))) return;
		if (sz[i] < sz[j]) swap(i, j);
		sz[i] += sz[j], id[j] = i;
		res = max(res, w);
	}
};

int main()
{
    _;

	int n, m; cin >> n >> m;
	vector<tuple<int, int, int>> ed(m);
	for (auto& [w, u, v] : ed) {
		cin >> u >> v >> w; u--, v--;
	}
	sort(ed.begin(), ed.end());

	DSU dsu(n);
	for (auto& [w, u, v] : ed) {
		dsu.merge(u, v, w);
	}
	cout << dsu.res << endl;
    
    return(0);
}
