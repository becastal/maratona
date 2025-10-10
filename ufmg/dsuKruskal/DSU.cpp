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

int main()
{
    _;

	int n, m; cin >> n >> m;
	DSU dsu(n);

	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		int u, v; cin >> u >> v; u--, v--;

		if (s == "union") {
			dsu.merge(u, v);
		} else {
			cout << (dsu.find(u) == dsu.find(v) ? "YES" : "NO") << endl;
		}
	}
    
    return(0);
}
