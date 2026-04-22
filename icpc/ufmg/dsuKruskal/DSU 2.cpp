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
	vector<int> id, sz, maxi, mini;
	DSU(int n) : id(n), sz(n, 1), maxi(n), mini(n) {
		iota(id.begin(), id.end(), 0);
		iota(maxi.begin(), maxi.end(), 1);
		iota(mini.begin(), mini.end(), 1);
	}

	int find(int i) {
		return (i == id[i] ? i : id[i] = find(id[i]));
	}

	void merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		if (sz[i] < sz[j]) swap(i, j);
		sz[i] += sz[j], id[j] = i;
		maxi[i] = max(maxi[i], maxi[j]);
		mini[i] = min(mini[i], mini[j]);
	}
};

int main()
{
    _;

	int n, m; cin >> n >> m;
	DSU dsu(n);

	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		
		if (s == "union") {
			int u, v; cin >> u >> v; u--, v--;
			dsu.merge(u, v);
		} else {
			int u; cin >> u; u--;	
			u = dsu.find(u);
			cout << dsu.mini[u] << ' ' << dsu.maxi[u] << ' ' << dsu.sz[u] << endl;
		}
	}
    
    return(0);
}
